int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
int V_10 ;
F_2 ( L_1 , V_11 ) ;
if ( ! V_2 -> V_12 -> V_13 )
V_2 -> V_14 = true ;
if ( ! V_4 -> V_13 )
V_2 -> V_15 = true ;
if ( ! V_4 -> V_16 ) {
V_2 -> V_15 = true ;
return 0 ;
}
V_4 -> V_17 = F_3 ( V_2 -> V_18 , V_2 -> V_19 , V_20 ) ;
if ( ! V_4 -> V_17 )
return - V_21 ;
V_4 -> V_22 = V_2 -> V_19 ;
V_6 = F_4 ( V_4 -> V_16 , 0 , 0 ) ;
if ( F_5 ( V_6 ) ) {
if ( F_6 ( V_6 ) == - V_23 ) {
V_2 -> V_15 = true ;
return 0 ;
}
return F_6 ( V_6 ) ;
}
V_9 = F_7 ( V_6 ) + sizeof( * V_8 ) ;
V_4 -> V_24 = F_8 ( V_6 ) ;
V_10 = - V_21 ;
V_4 -> V_25 = F_9 ( V_4 -> V_24 , V_20 ) ;
if ( ! V_4 -> V_25 )
goto error;
V_8 = F_10 ( V_9 , V_20 ) ;
if ( ! V_8 )
goto error;
V_8 -> V_6 = V_6 ;
V_8 -> V_26 = V_27 ;
V_10 = F_11 ( V_8 ) ;
if ( V_10 < 0 )
goto V_28;
F_12 () ;
V_10 = F_13 ( V_8 , V_2 -> V_29 , V_2 -> V_30 , V_4 -> V_25 ) ;
if ( V_10 < 0 )
goto V_28;
V_10 = F_14 ( V_4 -> V_25 , V_4 -> V_24 , L_2 ) ;
if ( V_10 == - V_31 ) {
F_15 ( L_3 ,
V_4 -> V_24 , V_4 -> V_25 ) ;
V_2 -> V_32 = true ;
V_10 = 0 ;
}
V_28:
F_16 ( V_8 ) ;
error:
F_17 ( V_6 ) ;
F_2 ( L_4 , V_11 , V_10 ) ;
return V_10 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_2 ( L_1 , V_11 ) ;
if ( V_2 -> V_33 != V_2 -> V_34 ||
memcmp ( V_2 -> V_35 , V_2 -> V_36 ,
V_2 -> V_34 ) != 0 )
goto V_37;
if ( V_2 -> V_4 -> V_38 [ 0 ] || V_2 -> V_4 -> V_38 [ 1 ] ) {
bool V_39 = F_19 ( V_2 -> V_40 , V_2 -> V_4 -> V_38 [ 1 ] ) ;
bool V_41 = F_19 ( V_2 -> V_42 , V_2 -> V_4 -> V_38 [ 0 ] ) ;
if ( ! V_39 && ! V_41 )
goto V_37;
V_10 = - V_31 ;
if ( ( ( V_39 && ! V_41 ) || ( V_41 && ! V_39 ) ) &&
V_2 -> V_4 -> V_38 [ 0 ] && V_2 -> V_4 -> V_38 [ 1 ] )
goto V_43;
}
V_10 = - V_31 ;
if ( V_2 -> V_12 -> V_13 != V_2 -> V_4 -> V_13 )
goto V_43;
V_10 = F_20 ( V_2 -> V_12 , V_2 -> V_4 ) ;
if ( V_10 < 0 ) {
if ( V_10 == - V_44 ) {
V_2 -> V_15 = true ;
V_10 = 0 ;
}
goto V_43;
}
F_2 ( L_5 ) ;
V_2 -> V_45 = true ;
V_43:
F_2 ( L_4 , V_11 , V_10 ) ;
return V_10 ;
V_37:
F_2 ( L_6 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_1 * V_2 ;
const char * V_50 ;
T_1 V_51 , V_52 ;
char * V_8 = NULL , * V_53 ;
int V_10 ;
V_2 = F_22 ( V_47 -> V_54 , V_47 -> V_55 ) ;
if ( F_5 ( V_2 ) )
return F_6 ( V_2 ) ;
F_2 ( L_7 , V_2 -> V_56 ) ;
F_2 ( L_8 , V_2 -> V_57 ) ;
if ( V_2 -> V_14 ) {
V_10 = - V_44 ;
goto V_58;
}
F_2 ( L_9 , V_2 -> V_12 -> V_13 ) ;
F_2 ( L_10 , V_2 -> V_59 , V_2 -> V_60 ) ;
V_2 -> V_12 -> V_61 = L_11 ;
if ( V_2 -> V_15 ) {
F_23 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
} else {
F_2 ( L_12 ,
V_2 -> V_4 -> V_13 , V_2 -> V_4 -> V_16 ) ;
}
V_10 = - V_31 ;
if ( V_2 -> V_32 )
goto V_58;
V_52 = strlen ( V_2 -> V_57 ) ;
if ( V_2 -> V_62 ) {
V_51 = V_2 -> V_63 ;
V_50 = V_2 -> V_62 ;
} else {
V_51 = V_2 -> V_64 ;
V_50 = V_2 -> V_65 ;
}
V_10 = - V_21 ;
V_8 = F_9 ( V_52 + 2 + V_51 * 2 + 1 , V_20 ) ;
if ( ! V_8 )
goto V_58;
V_53 = memcpy ( V_8 , V_2 -> V_57 , V_52 ) ;
V_53 += V_52 ;
* V_53 ++ = ':' ;
* V_53 ++ = ' ' ;
V_53 = F_24 ( V_53 , V_50 , V_51 ) ;
* V_53 = 0 ;
V_49 = F_9 ( sizeof( struct V_48 ) , V_20 ) ;
if ( ! V_49 )
goto V_66;
V_49 -> V_42 [ 0 ] = V_2 -> V_42 ;
V_49 -> V_42 [ 1 ] = V_2 -> V_40 ;
F_25 ( V_67 . V_68 ) ;
V_47 -> V_69 . V_54 [ V_70 ] = & V_67 ;
V_47 -> V_69 . V_54 [ V_71 ] = V_49 ;
V_47 -> V_69 . V_54 [ V_72 ] = V_2 -> V_12 ;
V_47 -> V_69 . V_54 [ V_73 ] = V_2 -> V_4 ;
V_47 -> V_74 = V_8 ;
V_47 -> V_75 = 100 ;
V_2 -> V_12 = NULL ;
V_2 -> V_42 = NULL ;
V_2 -> V_40 = NULL ;
V_2 -> V_4 = NULL ;
V_8 = NULL ;
V_10 = 0 ;
V_66:
F_16 ( V_8 ) ;
V_58:
F_26 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_76 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_76 ) ;
}
