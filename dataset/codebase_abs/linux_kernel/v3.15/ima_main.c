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
static void F_3 ( struct V_14 * V_14 )
{
struct V_15 * V_15 = F_4 ( V_14 ) ;
T_2 V_16 = V_14 -> V_17 ;
int V_18 ;
bool V_19 = false , V_20 = false ;
char * V_21 = NULL ;
const char * V_22 ;
if ( ! F_5 ( V_15 -> V_23 ) || ! V_24 )
return;
F_6 ( & V_15 -> V_25 ) ;
if ( V_16 & V_26 ) {
if ( F_7 ( & V_15 -> V_27 ) && F_8 ( V_15 ) )
V_19 = true ;
goto V_11;
}
V_18 = F_9 ( V_15 , V_28 , V_29 ) ;
if ( ! V_18 )
goto V_11;
if ( F_7 ( & V_15 -> V_30 ) > 0 )
V_20 = true ;
V_11:
F_10 ( & V_15 -> V_25 ) ;
if ( ! V_19 && ! V_20 )
return;
V_22 = F_11 ( & V_14 -> V_31 , & V_21 ) ;
if ( V_19 )
F_12 ( V_14 , V_22 , L_3 , L_4 ) ;
if ( V_20 )
F_12 ( V_14 , V_22 ,
L_3 , L_5 ) ;
F_13 ( V_21 ) ;
}
static void F_14 ( struct V_32 * V_33 ,
struct V_15 * V_15 , struct V_14 * V_14 )
{
T_2 V_16 = V_14 -> V_17 ;
if ( ! ( V_16 & V_26 ) )
return;
F_6 ( & V_15 -> V_25 ) ;
if ( F_7 ( & V_15 -> V_30 ) == 1 &&
V_33 -> V_34 != V_15 -> V_35 ) {
V_33 -> V_36 &= ~ V_37 ;
if ( V_33 -> V_36 & V_38 )
F_15 ( V_33 , V_14 ) ;
}
F_10 ( & V_15 -> V_25 ) ;
}
void F_16 ( struct V_14 * V_14 )
{
struct V_15 * V_15 = F_4 ( V_14 ) ;
struct V_32 * V_33 ;
if ( ! V_39 || ! F_5 ( V_15 -> V_23 ) )
return;
V_33 = F_17 ( V_15 ) ;
if ( ! V_33 )
return;
F_14 ( V_33 , V_15 , V_14 ) ;
}
static int F_18 ( struct V_14 * V_14 , const char * V_40 ,
int V_41 , int V_42 )
{
struct V_15 * V_15 = F_4 ( V_14 ) ;
struct V_32 * V_33 ;
struct V_2 * V_3 = F_2 () ;
char * V_21 = NULL ;
const char * V_22 = NULL ;
int V_43 = - V_44 , V_45 , V_46 , V_47 ;
struct V_48 * V_49 = NULL , * * V_50 = NULL ;
int V_51 = 0 ;
if ( ! V_24 || ! F_5 ( V_15 -> V_23 ) )
return 0 ;
V_45 = F_19 ( V_15 , V_41 , V_42 ) ;
if ( ! V_45 )
return 0 ;
V_46 = V_45 & V_38 ;
V_47 = ( V_45 & V_52 ) ? V_29 : V_42 ;
F_6 ( & V_15 -> V_25 ) ;
V_33 = F_20 ( V_15 ) ;
if ( ! V_33 )
goto V_11;
V_33 -> V_36 |= V_45 ;
V_45 &= V_53 ;
V_45 &= ~ ( ( V_33 -> V_36 & V_37 ) >> 1 ) ;
if ( ! V_45 ) {
if ( V_46 )
V_43 = F_21 ( V_33 , V_47 ) ;
goto V_54;
}
if ( strcmp ( V_3 -> V_6 , V_7 ) == 0 ) {
if ( V_45 & V_55 )
V_50 = & V_49 ;
} else
V_50 = & V_49 ;
V_43 = F_22 ( V_33 , V_14 , V_50 , & V_51 ) ;
if ( V_43 != 0 )
goto V_54;
V_22 = V_40 ? : F_11 ( & V_14 -> V_31 , & V_21 ) ;
if ( V_45 & V_56 )
F_23 ( V_33 , V_14 , V_22 ,
V_49 , V_51 ) ;
if ( V_45 & V_55 )
V_43 = F_24 ( V_47 , V_33 , V_14 , V_22 ,
V_49 , V_51 ) ;
if ( V_45 & V_57 )
F_25 ( V_33 , V_22 ) ;
F_13 ( V_21 ) ;
V_54:
if ( ( V_41 & V_58 ) && ( V_33 -> V_36 & V_59 ) )
V_43 = - V_60 ;
V_11:
F_10 ( & V_15 -> V_25 ) ;
F_13 ( V_49 ) ;
if ( ( V_43 && V_46 ) && ( V_61 & V_62 ) )
return - V_60 ;
return 0 ;
}
int F_26 ( struct V_14 * V_14 , unsigned long V_63 )
{
if ( V_14 && ( V_63 & V_64 ) )
return F_18 ( V_14 , NULL , V_65 , V_66 ) ;
return 0 ;
}
int F_27 ( struct V_67 * V_68 )
{
return F_18 ( V_68 -> V_14 ,
( strcmp ( V_68 -> V_40 , V_68 -> V_69 ) == 0 ) ?
V_68 -> V_40 : V_68 -> V_69 ,
V_65 , V_70 ) ;
}
int F_28 ( struct V_14 * V_14 , int V_41 )
{
F_3 ( V_14 ) ;
return F_18 ( V_14 , NULL ,
V_41 & ( V_28 | V_58 | V_65 ) ,
V_29 ) ;
}
int F_29 ( struct V_14 * V_14 )
{
if ( ! V_14 ) {
#ifndef F_30
if ( ( V_61 & V_71 ) &&
( V_61 & V_62 ) )
return - V_60 ;
#endif
return 0 ;
}
return F_18 ( V_14 , NULL , V_65 , V_72 ) ;
}
static int T_1 F_31 ( void )
{
int error ;
F_1 ( V_73 ) ;
error = F_32 () ;
if ( ! error )
V_24 = 1 ;
return error ;
}
