static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
T_1 V_7 ;
V_7 = F_3 ( V_5 , V_8 , L_1 , F_4 ( V_6 ) ) ;
V_5 [ V_7 - 1 ] = '\n' ;
return V_7 ;
}
static void F_5 ( char * V_9 , const char * V_10 )
{
for (; * V_10 ; V_10 ++ )
if ( * V_10 > ' ' && * V_10 < 127 && * V_10 != ':' )
* ( V_9 ++ ) = * V_10 ;
* V_9 = 0 ;
}
static T_1 F_6 ( char * V_11 , T_2 V_12 )
{
static const struct V_13 {
const char * V_14 ;
int V_6 ;
} V_15 [] = {
{ L_2 , V_16 } ,
{ L_3 , V_17 } ,
{ L_4 , V_18 } ,
{ L_5 , V_19 } ,
{ L_6 , V_20 } ,
{ L_7 , V_21 } ,
{ L_8 , V_22 } ,
{ L_9 , V_23 } ,
{ L_10 , V_24 } ,
{ L_11 , V_25 } ,
{ L_12 , V_26 } ,
{ L_13 , V_27 } ,
{ NULL , V_28 }
} ;
T_1 V_29 , V_30 ;
char * V_31 ;
const struct V_13 * V_32 ;
strcpy ( V_11 , L_14 ) ;
V_31 = V_11 + 3 ; V_30 = V_12 - 4 ;
for ( V_32 = V_15 ; V_32 -> V_14 && V_30 > 0 ; V_32 ++ ) {
const char * V_33 ;
char * V_34 ;
V_33 = F_4 ( V_32 -> V_6 ) ;
if ( ! V_33 )
continue;
V_34 = F_7 ( strlen ( V_33 ) + 1 , V_35 ) ;
if ( ! V_34 )
break;
F_5 ( V_34 , V_33 ) ;
V_29 = F_3 ( V_31 , V_30 , L_15 , V_32 -> V_14 , V_34 ) ;
F_8 ( V_34 ) ;
V_31 += V_29 ;
V_30 -= V_29 ;
}
V_31 [ 0 ] = ':' ;
V_31 [ 1 ] = 0 ;
return V_31 - V_11 + 1 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_36 ;
V_36 = F_6 ( V_5 , V_8 - 1 ) ;
V_5 [ V_36 ] = '\n' ;
V_5 [ V_36 + 1 ] = 0 ;
return V_36 + 1 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
T_1 V_7 ;
if ( F_11 ( V_38 , L_16 ) )
return - V_39 ;
V_7 = F_6 ( & V_38 -> V_40 [ V_38 -> V_41 - 1 ] ,
sizeof( V_38 -> V_40 ) - V_38 -> V_41 ) ;
if ( V_7 >= ( sizeof( V_38 -> V_40 ) - V_38 -> V_41 ) )
return - V_39 ;
V_38 -> V_41 += V_7 ;
return 0 ;
}
static void T_3 F_12 ( void )
{
int V_42 ;
V_42 = 0 ;
F_13 ( V_43 , V_16 ) ;
F_13 ( V_44 , V_17 ) ;
F_13 ( V_45 , V_18 ) ;
F_13 ( V_46 , V_19 ) ;
F_13 ( V_47 , V_20 ) ;
F_13 ( V_48 , V_21 ) ;
F_13 ( V_49 , V_50 ) ;
F_13 ( V_51 , V_52 ) ;
F_13 ( V_53 , V_54 ) ;
F_13 ( V_55 , V_22 ) ;
F_13 ( V_56 , V_23 ) ;
F_13 ( V_57 , V_24 ) ;
F_13 ( V_58 , V_59 ) ;
F_13 ( V_60 , V_61 ) ;
F_13 ( V_62 , V_25 ) ;
F_13 ( V_63 , V_26 ) ;
F_13 ( V_64 , V_27 ) ;
F_13 ( V_65 , V_66 ) ;
F_13 ( V_67 , V_68 ) ;
V_69 [ V_42 ++ ] = & V_70 . V_4 ;
}
static int T_3 F_14 ( void )
{
int V_71 ;
if ( ! V_72 )
return - V_73 ;
F_12 () ;
V_71 = F_15 ( & V_74 ) ;
if ( V_71 )
return V_71 ;
V_75 = F_16 ( sizeof( * V_75 ) , V_35 ) ;
if ( ! V_75 ) {
V_71 = - V_39 ;
goto V_76;
}
V_75 -> V_77 = & V_74 ;
F_17 ( V_75 , L_17 ) ;
V_75 -> V_78 = V_79 ;
V_71 = F_18 ( V_75 ) ;
if ( V_71 )
goto V_80;
return 0 ;
V_80:
F_19 ( V_75 ) ;
V_76:
F_20 ( & V_74 ) ;
return V_71 ;
}
