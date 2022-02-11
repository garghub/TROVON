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
if ( ! strcmp ( V_22 -> V_25 , V_11 ) )
return - V_26 ;
V_24 -> V_27 =
F_15 ( V_22 -> V_25 , V_16 | V_17 | V_18 ,
V_8 -> V_12 , & V_28 , V_22 ) ;
if ( ! V_24 -> V_27 )
return - V_20 ;
return 0 ;
}
void F_16 ( struct V_21 * V_22 )
{
F_17 ( V_23 ( V_22 ) -> V_27 ) ;
V_23 ( V_22 ) -> V_27 = NULL ;
}
static void * F_18 ( struct V_29 * V_30 , T_2 * V_31 )
__acquires( T_3 )
{
struct V_21 * V_32 ;
struct V_6 * V_6 = F_19 ( V_30 ) ;
T_2 V_33 = 1 ;
F_20 () ;
if ( * V_31 == 0 )
return V_34 ;
F_21 (net, dev) {
if ( ! F_22 ( V_32 ) )
continue;
if ( V_33 ++ == * V_31 )
return V_32 ;
}
return NULL ;
}
static void * F_23 ( struct V_29 * V_30 , void * V_35 , T_2 * V_31 )
{
struct V_21 * V_32 ;
struct V_6 * V_6 = F_19 ( V_30 ) ;
++ * V_31 ;
V_32 = V_35 ;
if ( V_35 == V_34 )
V_32 = F_24 ( & V_6 -> V_36 ) ;
F_25 (net, dev) {
if ( ! F_22 ( V_32 ) )
continue;
return V_32 ;
}
return NULL ;
}
static void F_26 ( struct V_29 * V_30 , void * V_35 )
__releases( T_3 )
{
F_27 () ;
}
static int F_28 ( struct V_29 * V_30 , void * V_35 )
{
struct V_6 * V_6 = F_19 ( V_30 ) ;
struct V_7 * V_8 = F_7 ( V_6 , V_9 ) ;
if ( V_35 == V_34 ) {
const char * V_37 = NULL ;
F_29 ( V_30 , L_2 ) ;
if ( V_8 -> V_38 < F_30 ( V_39 ) )
V_37 = V_39 [ V_8 -> V_38 ] ;
F_31 ( V_30 , L_3 ,
V_37 ? V_37 : L_4 ) ;
} else {
const struct V_21 * V_22 = V_35 ;
const struct V_23 * V_24 = V_23 ( V_22 ) ;
F_31 ( V_30 , L_5 , V_22 -> V_25 ,
V_24 -> V_40 , V_24 -> V_41 -> V_25 ) ;
}
return 0 ;
}
static int V_5 ( struct V_29 * V_30 , void * V_42 )
{
struct V_21 * V_22 = (struct V_21 * ) V_30 -> V_43 ;
const struct V_23 * V_24 = V_23 ( V_22 ) ;
struct V_44 V_45 ;
const struct V_44 * V_46 ;
static const char V_47 [] = L_6 ;
int V_33 ;
if ( ! F_22 ( V_22 ) )
return 0 ;
V_46 = F_32 ( V_22 , & V_45 ) ;
F_31 ( V_30 ,
L_7 ,
V_22 -> V_25 , V_24 -> V_40 ,
( int ) ( V_24 -> V_48 & 1 ) , V_22 -> V_49 ) ;
F_31 ( V_30 , V_47 , L_8 , V_46 -> V_50 ) ;
F_31 ( V_30 , V_47 , L_9 , V_46 -> V_51 ) ;
F_31 ( V_30 , V_47 , L_10 , V_46 -> V_52 ) ;
F_29 ( V_30 , L_11 ) ;
F_31 ( V_30 , V_47 , L_12 , V_46 -> V_53 ) ;
F_31 ( V_30 , V_47 , L_13 , V_46 -> V_54 ) ;
F_31 ( V_30 , L_14 , V_24 -> V_41 -> V_25 ) ;
F_31 ( V_30 , L_15
L_16 ,
V_24 -> V_55 [ 0 ] ,
V_24 -> V_55 [ 1 ] ,
V_24 -> V_55 [ 2 ] ,
V_24 -> V_55 [ 3 ] ,
V_24 -> V_55 [ 4 ] ,
V_24 -> V_55 [ 5 ] ,
V_24 -> V_55 [ 6 ] ,
V_24 -> V_55 [ 7 ] ) ;
F_31 ( V_30 , L_17 ) ;
for ( V_33 = 0 ; V_33 < 16 ; V_33 ++ ) {
const struct V_56 * V_57
= V_24 -> V_58 [ V_33 ] ;
while ( V_57 ) {
F_31 ( V_30 , L_18 ,
V_57 -> V_59 , ( ( V_57 -> V_60 >> 13 ) & 0x7 ) ) ;
V_57 = V_57 -> V_61 ;
}
}
F_29 ( V_30 , L_11 ) ;
return 0 ;
}
