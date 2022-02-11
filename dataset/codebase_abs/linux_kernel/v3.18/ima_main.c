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
F_9 ( V_14 , * V_19 , L_3 , L_4 ) ;
if ( V_24 )
F_9 ( V_14 , * V_19 ,
L_3 , L_5 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
struct V_20 * V_20 , struct V_14 * V_14 )
{
T_2 V_21 = V_14 -> V_22 ;
if ( ! ( V_21 & V_25 ) )
return;
F_11 ( & V_20 -> V_31 ) ;
if ( F_5 ( & V_20 -> V_29 ) == 1 ) {
if ( ( V_16 -> V_32 != V_20 -> V_33 ) ||
( V_16 -> V_27 & V_34 ) ) {
V_16 -> V_27 &= ~ ( V_35 | V_34 ) ;
if ( V_16 -> V_27 & V_36 )
F_12 ( V_16 , V_14 ) ;
}
}
F_13 ( & V_20 -> V_31 ) ;
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
static int F_16 ( struct V_14 * V_14 , int V_39 , int V_40 ,
int V_41 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 = NULL ;
struct V_2 * V_3 ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
int V_42 = - V_43 , V_44 , V_45 ;
struct V_46 * V_47 = NULL , * * V_48 = NULL ;
int V_49 = 0 ;
bool V_50 ;
if ( ! V_51 || ! F_15 ( V_20 -> V_38 ) )
return 0 ;
V_44 = F_17 ( V_20 , V_39 , V_40 ) ;
V_50 = ( ( V_40 == V_52 || V_40 == V_53 ) &&
( V_51 & V_28 ) ) ;
if ( ! V_44 && ! V_50 )
return 0 ;
V_45 = V_44 & V_36 ;
if ( V_44 & V_54 )
V_40 = V_52 ;
F_11 ( & V_20 -> V_31 ) ;
if ( V_44 ) {
V_16 = F_18 ( V_20 ) ;
if ( ! V_16 )
goto V_11;
}
if ( V_50 ) {
F_3 ( V_14 , V_16 , V_44 & V_28 ,
& V_18 , & V_19 ) ;
if ( ! V_44 ) {
V_42 = 0 ;
goto V_55;
}
}
V_16 -> V_27 |= V_44 ;
V_44 &= V_56 ;
V_44 &= ~ ( ( V_16 -> V_27 & V_35 ) >> 1 ) ;
if ( ! V_44 ) {
if ( V_45 )
V_42 = F_19 ( V_16 , V_40 ) ;
goto V_57;
}
V_3 = F_2 () ;
if ( ( V_44 & V_58 ) ||
strcmp ( V_3 -> V_6 , V_7 ) != 0 )
V_48 = & V_47 ;
V_42 = F_20 ( V_16 , V_14 , V_48 , & V_49 ) ;
if ( V_42 != 0 ) {
if ( V_14 -> V_59 & V_60 )
V_42 = ( V_16 -> V_27 & V_61 ) ? 0 : - V_62 ;
goto V_57;
}
if ( ! V_19 )
V_19 = F_8 ( & V_14 -> V_30 , & V_18 ) ;
if ( V_44 & V_28 )
F_21 ( V_16 , V_14 , V_19 ,
V_47 , V_49 ) ;
if ( V_44 & V_58 )
V_42 = F_22 ( V_40 , V_16 , V_14 , V_19 ,
V_47 , V_49 , V_41 ) ;
if ( V_44 & V_63 )
F_23 ( V_16 , V_19 ) ;
V_57:
if ( ( V_39 & V_64 ) && ( V_16 -> V_27 & V_65 ) )
V_42 = - V_62 ;
F_24 ( V_47 ) ;
V_55:
F_24 ( V_18 ) ;
V_11:
F_13 ( & V_20 -> V_31 ) ;
if ( ( V_42 && V_45 ) && ( V_66 & V_67 ) )
return - V_62 ;
return 0 ;
}
int F_25 ( struct V_14 * V_14 , unsigned long V_68 )
{
if ( V_14 && ( V_68 & V_69 ) )
return F_16 ( V_14 , V_70 , V_53 , 0 ) ;
return 0 ;
}
int F_26 ( struct V_71 * V_72 )
{
return F_16 ( V_72 -> V_14 , V_70 , V_73 , 0 ) ;
}
int F_27 ( struct V_14 * V_14 , int V_39 , int V_41 )
{
return F_16 ( V_14 ,
V_39 & ( V_74 | V_64 | V_70 ) ,
V_52 , V_41 ) ;
}
int F_28 ( struct V_14 * V_14 )
{
if ( ! V_14 ) {
#ifndef F_29
if ( ( V_66 & V_75 ) &&
( V_66 & V_67 ) )
return - V_62 ;
#endif
return 0 ;
}
return F_16 ( V_14 , V_70 , V_76 , 0 ) ;
}
int F_30 ( struct V_14 * V_14 , char * V_77 , T_3 V_78 )
{
if ( ! V_14 ) {
if ( ( V_66 & V_79 ) &&
( V_66 & V_67 ) )
return - V_62 ;
return 0 ;
}
return F_16 ( V_14 , V_70 , V_80 , 0 ) ;
}
static int T_1 F_31 ( void )
{
int error ;
F_1 ( V_81 ) ;
error = F_32 () ;
if ( ! error ) {
V_82 = 1 ;
F_33 () ;
}
return error ;
}
