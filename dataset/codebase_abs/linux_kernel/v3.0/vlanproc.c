static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 , V_2 , & V_3 ,
sizeof( struct V_4 ) ) ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_4 ( V_2 , V_5 , F_5 ( V_1 ) -> V_6 ) ;
}
void F_6 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_7 ( V_7 , V_10 ) ;
if ( V_9 -> V_11 )
F_8 ( V_12 , V_9 -> V_13 ) ;
if ( V_9 -> V_13 )
F_9 ( V_7 , V_14 ) ;
}
int T_1 F_10 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_7 ( V_7 , V_10 ) ;
V_9 -> V_13 = F_11 ( V_7 , V_14 , V_7 -> V_15 ) ;
if ( ! V_9 -> V_13 )
goto V_16;
V_9 -> V_11 = F_12 ( V_12 , V_17 | V_18 | V_19 ,
V_9 -> V_13 , & V_20 ) ;
if ( ! V_9 -> V_11 )
goto V_16;
return 0 ;
V_16:
F_13 ( L_1 , V_21 ) ;
F_6 ( V_7 ) ;
return - V_22 ;
}
int F_14 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_25 ( V_24 ) ;
struct V_8 * V_9 = F_7 ( F_15 ( V_24 ) , V_10 ) ;
V_26 -> V_27 =
F_16 ( V_24 -> V_28 , V_17 | V_18 | V_19 ,
V_9 -> V_13 , & V_29 , V_24 ) ;
if ( ! V_26 -> V_27 )
return - V_22 ;
return 0 ;
}
int F_17 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = F_7 ( F_15 ( V_24 ) , V_10 ) ;
if ( V_25 ( V_24 ) -> V_27 ) {
F_8 ( V_25 ( V_24 ) -> V_27 -> V_28 ,
V_9 -> V_13 ) ;
V_25 ( V_24 ) -> V_27 = NULL ;
}
return 0 ;
}
static void * F_18 ( struct V_30 * V_31 , T_2 * V_32 )
__acquires( T_3 )
{
struct V_23 * V_33 ;
struct V_7 * V_7 = F_19 ( V_31 ) ;
T_2 V_34 = 1 ;
F_20 () ;
if ( * V_32 == 0 )
return V_35 ;
F_21 (net, dev) {
if ( ! F_22 ( V_33 ) )
continue;
if ( V_34 ++ == * V_32 )
return V_33 ;
}
return NULL ;
}
static void * F_23 ( struct V_30 * V_31 , void * V_36 , T_2 * V_32 )
{
struct V_23 * V_33 ;
struct V_7 * V_7 = F_19 ( V_31 ) ;
++ * V_32 ;
V_33 = (struct V_23 * ) V_36 ;
if ( V_36 == V_35 )
V_33 = F_24 ( & V_7 -> V_37 ) ;
F_25 (net, dev) {
if ( ! F_22 ( V_33 ) )
continue;
return V_33 ;
}
return NULL ;
}
static void F_26 ( struct V_30 * V_31 , void * V_36 )
__releases( T_3 )
{
F_27 () ;
}
static int F_28 ( struct V_30 * V_31 , void * V_36 )
{
struct V_7 * V_7 = F_19 ( V_31 ) ;
struct V_8 * V_9 = F_7 ( V_7 , V_10 ) ;
if ( V_36 == V_35 ) {
const char * V_38 = NULL ;
F_29 ( V_31 , L_2 ) ;
if ( V_9 -> V_39 < F_30 ( V_40 ) )
V_38 = V_40 [ V_9 -> V_39 ] ;
F_31 ( V_31 , L_3 ,
V_38 ? V_38 : L_4 ) ;
} else {
const struct V_23 * V_24 = V_36 ;
const struct V_25 * V_26 = V_25 ( V_24 ) ;
F_31 ( V_31 , L_5 , V_24 -> V_28 ,
V_26 -> V_41 , V_26 -> V_42 -> V_28 ) ;
}
return 0 ;
}
static int V_5 ( struct V_30 * V_31 , void * V_43 )
{
struct V_23 * V_24 = (struct V_23 * ) V_31 -> V_44 ;
const struct V_25 * V_26 = V_25 ( V_24 ) ;
struct V_45 V_46 ;
const struct V_45 * V_47 ;
static const char V_48 [] = L_6 ;
int V_34 ;
if ( ! F_22 ( V_24 ) )
return 0 ;
V_47 = F_32 ( V_24 , & V_46 ) ;
F_31 ( V_31 ,
L_7 ,
V_24 -> V_28 , V_26 -> V_41 ,
( int ) ( V_26 -> V_49 & 1 ) , V_24 -> V_50 ) ;
F_31 ( V_31 , V_48 , L_8 , V_47 -> V_51 ) ;
F_31 ( V_31 , V_48 , L_9 , V_47 -> V_52 ) ;
F_31 ( V_31 , V_48 , L_10 , V_47 -> V_53 ) ;
F_29 ( V_31 , L_11 ) ;
F_31 ( V_31 , V_48 , L_12 , V_47 -> V_54 ) ;
F_31 ( V_31 , V_48 , L_13 , V_47 -> V_55 ) ;
F_31 ( V_31 , L_14 , V_26 -> V_42 -> V_28 ) ;
F_31 ( V_31 , L_15
L_16 ,
V_26 -> V_56 [ 0 ] ,
V_26 -> V_56 [ 1 ] ,
V_26 -> V_56 [ 2 ] ,
V_26 -> V_56 [ 3 ] ,
V_26 -> V_56 [ 4 ] ,
V_26 -> V_56 [ 5 ] ,
V_26 -> V_56 [ 6 ] ,
V_26 -> V_56 [ 7 ] ) ;
F_31 ( V_31 , L_17 ) ;
for ( V_34 = 0 ; V_34 < 16 ; V_34 ++ ) {
const struct V_57 * V_58
= V_26 -> V_59 [ V_34 ] ;
while ( V_58 ) {
F_31 ( V_31 , L_18 ,
V_58 -> V_60 , ( ( V_58 -> V_61 >> 13 ) & 0x7 ) ) ;
V_58 = V_58 -> V_62 ;
}
}
F_29 ( V_31 , L_11 ) ;
return 0 ;
}
