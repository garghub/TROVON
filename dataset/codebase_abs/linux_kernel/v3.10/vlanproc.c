static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 , V_2 , & V_3 ,
sizeof( struct V_4 ) ) ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_4 ( V_2 , V_5 , F_5 ( V_1 ) ) ;
}
void F_6 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = F_7 ( V_6 , V_9 ) ;
if ( V_8 -> V_10 )
F_8 ( V_11 , V_8 -> V_12 ) ;
if ( V_8 -> V_12 )
F_8 ( V_13 , V_6 -> V_14 ) ;
}
int T_1 F_9 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = F_7 ( V_6 , V_9 ) ;
V_8 -> V_12 = F_10 ( V_6 , V_13 , V_6 -> V_14 ) ;
if ( ! V_8 -> V_12 )
goto V_15;
V_8 -> V_10 = F_11 ( V_11 , V_16 | V_17 | V_18 ,
V_8 -> V_12 , & V_19 ) ;
if ( ! V_8 -> V_10 )
goto V_15;
return 0 ;
V_15:
F_12 ( L_1 ) ;
F_6 ( V_6 ) ;
return - V_20 ;
}
int F_13 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_23 ( V_22 ) ;
struct V_7 * V_8 = F_7 ( F_14 ( V_22 ) , V_9 ) ;
V_24 -> V_25 =
F_15 ( V_22 -> V_26 , V_16 | V_17 | V_18 ,
V_8 -> V_12 , & V_27 , V_22 ) ;
if ( ! V_24 -> V_25 )
return - V_20 ;
return 0 ;
}
int F_16 ( struct V_21 * V_22 )
{
F_17 ( V_23 ( V_22 ) -> V_25 ) ;
V_23 ( V_22 ) -> V_25 = NULL ;
return 0 ;
}
static void * F_18 ( struct V_28 * V_29 , T_2 * V_30 )
__acquires( T_3 )
{
struct V_21 * V_31 ;
struct V_6 * V_6 = F_19 ( V_29 ) ;
T_2 V_32 = 1 ;
F_20 () ;
if ( * V_30 == 0 )
return V_33 ;
F_21 (net, dev) {
if ( ! F_22 ( V_31 ) )
continue;
if ( V_32 ++ == * V_30 )
return V_31 ;
}
return NULL ;
}
static void * F_23 ( struct V_28 * V_29 , void * V_34 , T_2 * V_30 )
{
struct V_21 * V_31 ;
struct V_6 * V_6 = F_19 ( V_29 ) ;
++ * V_30 ;
V_31 = V_34 ;
if ( V_34 == V_33 )
V_31 = F_24 ( & V_6 -> V_35 ) ;
F_25 (net, dev) {
if ( ! F_22 ( V_31 ) )
continue;
return V_31 ;
}
return NULL ;
}
static void F_26 ( struct V_28 * V_29 , void * V_34 )
__releases( T_3 )
{
F_27 () ;
}
static int F_28 ( struct V_28 * V_29 , void * V_34 )
{
struct V_6 * V_6 = F_19 ( V_29 ) ;
struct V_7 * V_8 = F_7 ( V_6 , V_9 ) ;
if ( V_34 == V_33 ) {
const char * V_36 = NULL ;
F_29 ( V_29 , L_2 ) ;
if ( V_8 -> V_37 < F_30 ( V_38 ) )
V_36 = V_38 [ V_8 -> V_37 ] ;
F_31 ( V_29 , L_3 ,
V_36 ? V_36 : L_4 ) ;
} else {
const struct V_21 * V_22 = V_34 ;
const struct V_23 * V_24 = V_23 ( V_22 ) ;
F_31 ( V_29 , L_5 , V_22 -> V_26 ,
V_24 -> V_39 , V_24 -> V_40 -> V_26 ) ;
}
return 0 ;
}
static int V_5 ( struct V_28 * V_29 , void * V_41 )
{
struct V_21 * V_22 = (struct V_21 * ) V_29 -> V_42 ;
const struct V_23 * V_24 = V_23 ( V_22 ) ;
struct V_43 V_44 ;
const struct V_43 * V_45 ;
static const char V_46 [] = L_6 ;
int V_32 ;
if ( ! F_22 ( V_22 ) )
return 0 ;
V_45 = F_32 ( V_22 , & V_44 ) ;
F_31 ( V_29 ,
L_7 ,
V_22 -> V_26 , V_24 -> V_39 ,
( int ) ( V_24 -> V_47 & 1 ) , V_22 -> V_48 ) ;
F_31 ( V_29 , V_46 , L_8 , V_45 -> V_49 ) ;
F_31 ( V_29 , V_46 , L_9 , V_45 -> V_50 ) ;
F_31 ( V_29 , V_46 , L_10 , V_45 -> V_51 ) ;
F_29 ( V_29 , L_11 ) ;
F_31 ( V_29 , V_46 , L_12 , V_45 -> V_52 ) ;
F_31 ( V_29 , V_46 , L_13 , V_45 -> V_53 ) ;
F_31 ( V_29 , L_14 , V_24 -> V_40 -> V_26 ) ;
F_31 ( V_29 , L_15
L_16 ,
V_24 -> V_54 [ 0 ] ,
V_24 -> V_54 [ 1 ] ,
V_24 -> V_54 [ 2 ] ,
V_24 -> V_54 [ 3 ] ,
V_24 -> V_54 [ 4 ] ,
V_24 -> V_54 [ 5 ] ,
V_24 -> V_54 [ 6 ] ,
V_24 -> V_54 [ 7 ] ) ;
F_31 ( V_29 , L_17 ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
const struct V_55 * V_56
= V_24 -> V_57 [ V_32 ] ;
while ( V_56 ) {
F_31 ( V_29 , L_18 ,
V_56 -> V_58 , ( ( V_56 -> V_59 >> 13 ) & 0x7 ) ) ;
V_56 = V_56 -> V_60 ;
}
}
F_29 ( V_29 , L_11 ) ;
return 0 ;
}
