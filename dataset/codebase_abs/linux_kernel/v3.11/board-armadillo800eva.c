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
struct V_1 * V_35 = NULL ;
F_35 ( 0 , L_15 , V_36 ,
F_36 ( V_36 ) , 3300000 ) ;
F_37 ( V_37 , F_36 ( V_37 ) ) ;
F_38 () ;
F_39 () ;
F_40 ( 61 , V_38 , NULL ) ;
F_40 ( 202 , V_39 , NULL ) ;
F_40 ( 18 , V_38 , NULL ) ;
F_40 ( 159 , V_40 , NULL ) ;
if ( F_10 ( 159 ) ) {
} else {
F_40 ( 209 , V_40 , NULL ) ;
F_41 ( & V_41 ) ;
V_35 = & V_41 ;
}
F_40 ( 173 , V_39 , NULL ) ;
F_40 ( 172 , V_38 , NULL ) ;
F_40 ( 158 , V_39 , NULL ) ;
F_42 ( 7 , NULL ) ;
F_42 ( 8 , NULL ) ;
F_43 ( V_42 ) ;
F_43 ( V_43 ) ;
F_40 ( 176 , V_38 , NULL ) ;
F_40 ( 6 , V_40 , NULL ) ;
if ( F_10 ( 6 ) ) {
} else {
F_37 ( V_44 ,
F_36 ( V_44 ) ) ;
F_41 ( & V_45 ) ;
F_41 ( & V_46 ) ;
}
#ifdef F_44
F_45 ( F_46 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_47 ( 0 , V_47 , F_36 ( V_47 ) ) ;
F_47 ( 2 , V_48 , F_36 ( V_48 ) ) ;
F_48 () ;
F_49 ( V_49 ,
F_36 ( V_49 ) ) ;
F_50 ( L_16 , & V_50 ) ;
F_50 ( L_16 , & V_51 ) ;
if ( V_35 )
F_50 ( L_17 , V_35 ) ;
F_51 () ;
}
static void T_3 F_52 ( void )
{
F_53 ( V_52 | V_53 ) ;
F_54 () ;
F_31 () ;
}
static void T_3 F_55 ( void )
{
F_56 () ;
}
static void F_57 ( enum V_54 V_27 , const char * V_55 )
{
F_58 ( ( 1 << 31 ) , V_56 ) ;
}
