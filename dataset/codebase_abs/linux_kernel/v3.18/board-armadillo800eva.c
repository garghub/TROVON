static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 ,
void T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_7 -> V_8 ) ;
F_4 ( V_7 -> V_9 ) ;
F_4 ( V_7 -> V_10 ) ;
F_4 ( V_7 -> V_11 ) ;
F_4 ( V_7 -> V_12 ) ;
F_5 ( 0xd750 , V_13 ) ;
F_6 ( 1 ) ;
F_7 ( 0x0000000c , V_7 -> V_14 + V_15 ) ;
F_7 ( 0x00000008 , V_7 -> V_14 + V_15 ) ;
F_6 ( 10 ) ;
F_5 ( 0xd770 , V_13 ) ;
F_5 ( 0x4000 , V_4 + 0x102 ) ;
} else {
F_7 ( 0x0000010f , V_7 -> V_14 + V_15 ) ;
F_5 ( 0xd7c0 , V_13 ) ;
F_8 ( V_7 -> V_12 ) ;
F_8 ( V_7 -> V_11 ) ;
F_8 ( V_7 -> V_10 ) ;
F_8 ( V_7 -> V_9 ) ;
F_8 ( V_7 -> V_8 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( 209 ) ;
}
static T_2 F_11 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
F_12 ( V_2 ) ;
return V_18 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! F_14 ( V_7 -> V_12 ) )
F_15 ( V_7 -> V_12 ) ;
if ( ! F_14 ( V_7 -> V_8 ) )
F_15 ( V_7 -> V_8 ) ;
if ( ! F_14 ( V_7 -> V_9 ) )
F_15 ( V_7 -> V_9 ) ;
if ( ! F_14 ( V_7 -> V_10 ) )
F_15 ( V_7 -> V_10 ) ;
if ( ! F_14 ( V_7 -> V_11 ) )
F_15 ( V_7 -> V_11 ) ;
if ( V_7 -> V_14 )
F_16 ( V_7 -> V_14 ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = NULL ;
V_7 -> V_14 = NULL ;
F_17 ( V_19 , V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_20 ;
V_7 -> V_12 = F_19 ( & V_2 -> V_21 , L_1 ) ;
V_7 -> V_8 = F_19 ( & V_2 -> V_21 , L_2 ) ;
V_7 -> V_9 = F_19 ( & V_2 -> V_21 , L_3 ) ;
V_7 -> V_11 = F_19 ( & V_2 -> V_21 , L_4 ) ;
V_7 -> V_10 = F_19 ( & V_2 -> V_21 , L_5 ) ;
V_7 -> V_14 = F_20 ( V_22 , 0x20000 ) ;
if ( F_14 ( V_7 -> V_12 ) ||
F_14 ( V_7 -> V_8 ) ||
F_14 ( V_7 -> V_9 ) ||
F_14 ( V_7 -> V_10 ) ||
F_14 ( V_7 -> V_11 ) ||
! V_7 -> V_14 ) {
F_21 ( & V_2 -> V_21 , L_6 ) ;
F_13 ( V_2 ) ;
return - V_23 ;
}
V_20 = F_22 ( V_19 , F_11 , V_24 ,
F_23 ( & V_2 -> V_21 ) , V_2 ) ;
if ( V_20 ) {
F_21 ( & V_2 -> V_21 , L_7 ) ;
return V_20 ;
}
F_24 ( V_19 , V_25 ) ;
F_25 ( V_7 -> V_8 ,
F_26 ( F_27 ( V_7 -> V_8 ) ) ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_21 , int V_27 )
{
struct V_28 * V_29 = F_19 ( NULL , L_8 ) ;
if ( F_14 ( V_29 ) ) {
F_21 ( V_21 , L_9 ) ;
return - V_30 ;
}
if ( V_27 ) {
F_25 ( V_29 , F_29 ( V_29 , 24000000 ) ) ;
F_4 ( V_29 ) ;
F_30 ( 158 , 1 ) ;
} else {
F_30 ( 158 , 0 ) ;
F_8 ( V_29 ) ;
}
F_15 ( V_29 ) ;
return 0 ;
}
static void T_3 F_31 ( void )
{
struct V_28 * system = F_19 ( NULL , L_10 ) ;
struct V_28 * V_31 = F_19 ( NULL , L_11 ) ;
struct V_28 * V_32 = F_19 ( NULL , L_12 ) ;
struct V_28 * V_33 = F_19 ( NULL , L_13 ) ;
if ( F_14 ( system ) ||
F_14 ( V_31 ) ||
F_14 ( V_32 ) ||
F_14 ( V_33 ) ) {
F_32 ( L_14 ) ;
goto V_34;
}
F_25 ( V_31 , 24000000 ) ;
F_33 ( V_32 , system ) ;
F_25 ( V_33 , 12288000 ) ;
V_34:
if ( ! F_14 ( system ) )
F_15 ( system ) ;
if ( ! F_14 ( V_31 ) )
F_15 ( V_31 ) ;
if ( ! F_14 ( V_32 ) )
F_15 ( V_32 ) ;
if ( ! F_14 ( V_33 ) )
F_15 ( V_33 ) ;
}
static void T_3 F_34 ( void )
{
static struct V_35 V_36 [] V_37 = {
{ L_15 , & V_38 } ,
{ L_15 , & V_39 } ,
} ;
struct V_1 * V_40 = NULL ;
F_35 ( 0 , L_16 , V_41 ,
F_36 ( V_41 ) , 3300000 ) ;
F_35 ( 3 , L_17 , V_42 ,
F_36 ( V_42 ) , 5000000 ) ;
F_37 ( V_43 , F_36 ( V_43 ) ) ;
F_38 ( V_44 , F_36 ( V_44 ) ) ;
F_39 () ;
F_40 () ;
F_41 ( 18 , V_45 , NULL ) ;
F_41 ( 159 , V_46 , NULL ) ;
if ( F_10 ( 159 ) ) {
} else {
F_41 ( 209 , V_46 , NULL ) ;
F_42 ( & V_47 ) ;
V_40 = & V_47 ;
}
F_41 ( 173 , V_48 , NULL ) ;
F_41 ( 172 , V_45 , NULL ) ;
F_41 ( 158 , V_48 , NULL ) ;
F_43 ( 7 , NULL ) ;
F_43 ( 8 , NULL ) ;
F_44 ( V_49 ) ;
F_44 ( V_50 ) ;
F_41 ( 176 , V_45 , NULL ) ;
F_41 ( 6 , V_46 , NULL ) ;
if ( F_10 ( 6 ) ) {
} else {
F_37 ( V_51 ,
F_36 ( V_51 ) ) ;
F_42 ( & V_52 ) ;
F_42 ( & V_53 ) ;
}
#ifdef F_45
F_46 ( F_47 ( 0xf0002000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_48 ( 0 , V_54 , F_36 ( V_54 ) ) ;
F_48 ( 2 , V_55 , F_36 ( V_55 ) ) ;
F_49 () ;
F_50 ( V_56 ,
F_36 ( V_56 ) ) ;
F_51 ( V_36 ,
F_36 ( V_36 ) ) ;
if ( V_40 )
F_52 ( L_18 , V_40 ) ;
F_53 () ;
}
static void T_3 F_54 ( void )
{
F_55 ( V_57 | V_58 ) ;
F_56 () ;
F_31 () ;
}
static void F_57 ( enum V_59 V_27 , const char * V_60 )
{
F_58 ( ( 1 << 31 ) , V_61 ) ;
}
