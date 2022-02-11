static int T_1 F_1 ( char * V_1 )
{
struct V_2 * V_3 = F_2 () ;
int V_4 ;
if ( V_5 )
return 1 ;
if ( strcmp ( V_3 -> V_6 , V_7 ) == 0 ) {
if ( strncmp ( V_1 , L_1 , 4 ) == 0 )
V_8 = V_9 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_8 = V_10 ;
goto V_11;
}
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( strcmp ( V_1 , V_13 [ V_4 ] ) == 0 ) {
V_8 = V_4 ;
break;
}
}
V_11:
V_5 = 1 ;
return 1 ;
}
static void F_3 ( struct V_14 * V_14 ,
struct V_15 * V_16 ,
int V_17 ,
char * * V_18 ,
const char * * V_19 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
T_2 V_21 = V_14 -> V_22 ;
bool V_23 = false , V_24 = false ;
if ( V_21 & V_25 ) {
if ( F_5 ( & V_20 -> V_26 ) && F_6 ( V_20 ) ) {
if ( ! V_16 )
V_16 = F_7 ( V_20 ) ;
if ( V_16 && ( V_16 -> V_27 & V_28 ) )
V_23 = true ;
}
} else {
if ( ( F_5 ( & V_20 -> V_29 ) > 0 ) && V_17 )
V_24 = true ;
}
if ( ! V_23 && ! V_24 )
return;
* V_19 = F_8 ( & V_14 -> V_30 , V_18 ) ;
if ( V_23 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_4 ) ;
if ( V_24 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_5 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
struct V_20 * V_20 , struct V_14 * V_14 )
{
T_2 V_21 = V_14 -> V_22 ;
if ( ! ( V_21 & V_25 ) )
return;
F_11 ( V_20 ) ;
if ( F_5 ( & V_20 -> V_29 ) == 1 ) {
if ( ( V_16 -> V_31 != V_20 -> V_32 ) ||
( V_16 -> V_27 & V_33 ) ) {
V_16 -> V_27 &= ~ ( V_34 | V_33 ) ;
V_16 -> V_35 = 0 ;
if ( V_16 -> V_27 & V_36 )
F_12 ( V_16 , V_14 ) ;
}
}
F_13 ( V_20 ) ;
}
void F_14 ( struct V_14 * V_14 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 ;
if ( ! V_37 || ! F_15 ( V_20 -> V_38 ) )
return;
V_16 = F_7 ( V_20 ) ;
if ( ! V_16 )
return;
F_10 ( V_16 , V_20 , V_14 ) ;
}
static int F_16 ( struct V_14 * V_14 , char * V_39 , T_3 V_40 ,
int V_41 , enum V_42 V_43 , int V_44 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 = NULL ;
struct V_2 * V_3 ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
int V_45 = - V_46 , V_47 , V_48 ;
int V_49 = V_50 ;
struct V_51 * V_52 = NULL ;
int V_53 = 0 ;
bool V_54 ;
enum V_55 V_55 ;
if ( ! V_37 || ! F_15 ( V_20 -> V_38 ) )
return 0 ;
V_47 = F_17 ( V_20 , V_41 , V_43 , & V_49 ) ;
V_54 = ( ( V_43 == V_56 || V_43 == V_57 ) &&
( V_37 & V_28 ) ) ;
if ( ! V_47 && ! V_54 )
return 0 ;
V_48 = V_47 & V_36 ;
if ( V_47 & V_58 )
V_43 = V_56 ;
F_11 ( V_20 ) ;
if ( V_47 ) {
V_16 = F_18 ( V_20 ) ;
if ( ! V_16 )
goto V_11;
}
if ( V_54 ) {
F_3 ( V_14 , V_16 , V_47 & V_28 ,
& V_18 , & V_19 ) ;
if ( ! V_47 ) {
V_45 = 0 ;
goto V_59;
}
}
V_16 -> V_27 |= V_47 ;
V_47 &= V_60 ;
V_47 &= ~ ( ( V_16 -> V_27 & ( V_34 ^ V_61 ) ) >> 1 ) ;
if ( ( V_47 & V_28 ) && ( V_16 -> V_35 & ( 0x1 << V_49 ) ) )
V_47 ^= V_28 ;
if ( ! V_47 ) {
if ( V_48 )
V_45 = F_19 ( V_16 , V_43 ) ;
goto V_62;
}
V_3 = F_2 () ;
if ( ( V_47 & V_63 ) ||
strcmp ( V_3 -> V_6 , V_7 ) != 0 )
V_53 = F_20 ( F_21 ( V_14 ) , & V_52 ) ;
V_55 = F_22 ( V_52 , V_53 ) ;
V_45 = F_23 ( V_16 , V_14 , V_39 , V_40 , V_55 ) ;
if ( V_45 != 0 ) {
if ( V_14 -> V_64 & V_65 )
V_45 = ( V_16 -> V_27 & V_66 ) ? 0 : - V_67 ;
goto V_62;
}
if ( ! V_19 )
V_19 = F_8 ( & V_14 -> V_30 , & V_18 ) ;
if ( V_47 & V_28 )
F_24 ( V_16 , V_14 , V_19 ,
V_52 , V_53 , V_49 ) ;
if ( V_47 & V_63 )
V_45 = F_25 ( V_43 , V_16 , V_14 , V_19 ,
V_52 , V_53 , V_44 ) ;
if ( V_47 & V_68 )
F_26 ( V_16 , V_19 ) ;
V_62:
if ( ( V_41 & V_69 ) && ( V_16 -> V_27 & V_70 ) &&
! ( V_16 -> V_27 & V_33 ) )
V_45 = - V_67 ;
F_27 ( V_52 ) ;
V_59:
if ( V_18 )
F_28 ( V_18 ) ;
V_11:
F_13 ( V_20 ) ;
if ( ( V_45 && V_48 ) && ( V_71 & V_72 ) )
return - V_67 ;
return 0 ;
}
int F_29 ( struct V_14 * V_14 , unsigned long V_73 )
{
if ( V_14 && ( V_73 & V_74 ) )
return F_16 ( V_14 , NULL , 0 , V_75 ,
V_57 , 0 ) ;
return 0 ;
}
int F_30 ( struct V_76 * V_77 )
{
return F_16 ( V_77 -> V_14 , NULL , 0 , V_75 ,
V_78 , 0 ) ;
}
int F_31 ( struct V_14 * V_14 , int V_41 , int V_44 )
{
return F_16 ( V_14 , NULL , 0 ,
V_41 & ( V_79 | V_69 | V_75 ) ,
V_56 , V_44 ) ;
}
void F_32 ( struct V_80 * V_80 )
{
struct V_15 * V_16 ;
struct V_20 * V_20 = V_80 -> V_81 ;
int V_48 ;
V_48 = F_33 ( V_20 , V_82 , V_56 ) ;
if ( ! V_48 )
return;
V_16 = F_18 ( V_20 ) ;
if ( V_16 )
V_16 -> V_27 |= V_33 ;
}
int F_34 ( struct V_14 * V_14 , enum V_83 V_84 )
{
if ( ! V_14 && V_84 == V_85 ) {
#ifndef F_35
if ( ( V_71 & V_86 ) &&
( V_71 & V_72 ) )
return - V_67 ;
#endif
return 0 ;
}
return 0 ;
}
int F_36 ( struct V_14 * V_14 , void * V_39 , T_3 V_40 ,
enum V_83 V_84 )
{
enum V_42 V_43 ;
if ( ! V_14 && V_84 == V_87 ) {
if ( ( V_71 & V_88 ) &&
( V_71 & V_72 ) )
return - V_67 ;
return 0 ;
}
if ( ! V_14 && V_84 == V_85 )
return 0 ;
if ( ! V_14 || ! V_39 || V_40 == 0 ) {
if ( V_71 & V_72 )
return - V_67 ;
return 0 ;
}
V_43 = V_89 [ V_84 ] ? : V_56 ;
return F_16 ( V_14 , V_39 , V_40 , V_79 , V_43 , 0 ) ;
}
static int T_1 F_37 ( void )
{
int error ;
F_1 ( V_90 ) ;
error = F_38 () ;
if ( ! error ) {
V_91 = 1 ;
F_39 () ;
}
return error ;
}
