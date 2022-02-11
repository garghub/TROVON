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
struct V_15 * V_15 = V_14 -> V_16 . V_15 ;
struct V_17 * V_17 = F_4 ( V_14 ) ;
T_2 V_18 = V_14 -> V_19 ;
int V_20 ;
bool V_21 = false , V_22 = false ;
char * V_23 = NULL ;
const char * V_24 ;
if ( ! F_5 ( V_17 -> V_25 ) || ! V_26 )
return;
F_6 ( & V_17 -> V_27 ) ;
if ( V_18 & V_28 ) {
if ( F_7 ( & V_17 -> V_29 ) && F_8 ( V_17 ) )
V_21 = true ;
goto V_11;
}
V_20 = F_9 ( V_17 , V_30 , V_31 ) ;
if ( ! V_20 )
goto V_11;
if ( F_7 ( & V_17 -> V_32 ) > 0 )
V_22 = true ;
V_11:
F_10 ( & V_17 -> V_27 ) ;
if ( ! V_21 && ! V_22 )
return;
V_24 = F_11 ( & V_14 -> V_16 , & V_23 ) ;
if ( ! V_24 || strlen ( V_24 ) > V_33 )
V_24 = V_15 -> V_34 . V_6 ;
if ( V_21 )
F_12 ( V_14 , V_24 , L_3 , L_4 ) ;
if ( V_22 )
F_12 ( V_14 , V_24 ,
L_3 , L_5 ) ;
F_13 ( V_23 ) ;
}
static void F_14 ( struct V_35 * V_36 ,
struct V_17 * V_17 , struct V_14 * V_14 )
{
T_2 V_18 = V_14 -> V_19 ;
if ( ! ( V_18 & V_28 ) )
return;
F_6 ( & V_17 -> V_27 ) ;
if ( F_7 ( & V_17 -> V_32 ) == 1 &&
V_36 -> V_37 != V_17 -> V_38 ) {
V_36 -> V_39 &= ~ V_40 ;
if ( V_36 -> V_39 & V_41 )
F_15 ( V_36 , V_14 ) ;
}
F_10 ( & V_17 -> V_27 ) ;
}
void F_16 ( struct V_14 * V_14 )
{
struct V_17 * V_17 = F_4 ( V_14 ) ;
struct V_35 * V_36 ;
if ( ! V_42 || ! F_5 ( V_17 -> V_25 ) )
return;
V_36 = F_17 ( V_17 ) ;
if ( ! V_36 )
return;
F_14 ( V_36 , V_17 , V_14 ) ;
}
static int F_18 ( struct V_14 * V_14 , const char * V_43 ,
int V_44 , int V_45 )
{
struct V_17 * V_17 = F_4 ( V_14 ) ;
struct V_35 * V_36 ;
struct V_2 * V_3 = F_2 () ;
char * V_23 = NULL ;
const char * V_24 = NULL ;
int V_46 = - V_47 , V_48 , V_49 , V_50 ;
struct V_51 * V_52 = NULL , * * V_53 = NULL ;
int V_54 = 0 ;
if ( ! V_26 || ! F_5 ( V_17 -> V_25 ) )
return 0 ;
V_48 = F_19 ( V_17 , V_44 , V_45 ) ;
if ( ! V_48 )
return 0 ;
V_49 = V_48 & V_41 ;
V_50 = ( V_48 & V_55 ) ? V_31 : V_45 ;
F_6 ( & V_17 -> V_27 ) ;
V_36 = F_20 ( V_17 ) ;
if ( ! V_36 )
goto V_11;
V_36 -> V_39 |= V_48 ;
V_48 &= V_56 ;
V_48 &= ~ ( ( V_36 -> V_39 & V_40 ) >> 1 ) ;
if ( ! V_48 ) {
if ( V_49 )
V_46 = F_21 ( V_36 , V_50 ) ;
goto V_57;
}
if ( strcmp ( V_3 -> V_6 , V_7 ) == 0 ) {
if ( V_48 & V_58 )
V_53 = & V_52 ;
} else
V_53 = & V_52 ;
V_46 = F_22 ( V_36 , V_14 , V_53 , & V_54 ) ;
if ( V_46 != 0 )
goto V_57;
V_24 = ! V_43 ? F_11 ( & V_14 -> V_16 , & V_23 ) : V_43 ;
if ( ! V_24 )
V_24 = ( const char * ) V_14 -> V_59 -> V_34 . V_6 ;
if ( V_48 & V_60 )
F_23 ( V_36 , V_14 , V_24 ,
V_52 , V_54 ) ;
if ( V_48 & V_58 )
V_46 = F_24 ( V_50 , V_36 , V_14 , V_24 ,
V_52 , V_54 ) ;
if ( V_48 & V_61 )
F_25 ( V_36 , V_24 ) ;
F_13 ( V_23 ) ;
V_57:
if ( ( V_44 & V_62 ) && ( V_36 -> V_39 & V_63 ) )
V_46 = - V_64 ;
V_11:
F_10 ( & V_17 -> V_27 ) ;
F_13 ( V_52 ) ;
if ( ( V_46 && V_49 ) && ( V_65 & V_66 ) )
return - V_64 ;
return 0 ;
}
int F_26 ( struct V_14 * V_14 , unsigned long V_67 )
{
if ( V_14 && ( V_67 & V_68 ) )
return F_18 ( V_14 , NULL , V_69 , V_70 ) ;
return 0 ;
}
int F_27 ( struct V_71 * V_72 )
{
return F_18 ( V_72 -> V_14 ,
( strcmp ( V_72 -> V_43 , V_72 -> V_73 ) == 0 ) ?
V_72 -> V_43 : V_72 -> V_73 ,
V_69 , V_74 ) ;
}
int F_28 ( struct V_14 * V_14 , int V_44 )
{
F_3 ( V_14 ) ;
return F_18 ( V_14 , NULL ,
V_44 & ( V_30 | V_62 | V_69 ) ,
V_31 ) ;
}
int F_29 ( struct V_14 * V_14 )
{
if ( ! V_14 ) {
#ifndef F_30
if ( ( V_65 & V_75 ) &&
( V_65 & V_66 ) )
return - V_64 ;
#endif
return 0 ;
}
return F_18 ( V_14 , NULL , V_69 , V_76 ) ;
}
static int T_1 F_31 ( void )
{
int error ;
F_1 ( V_77 ) ;
error = F_32 () ;
if ( ! error )
V_26 = 1 ;
return error ;
}
