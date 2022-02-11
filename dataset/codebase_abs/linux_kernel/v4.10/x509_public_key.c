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
V_28:
F_14 ( V_8 ) ;
error:
F_15 ( V_6 ) ;
F_2 ( L_2 , V_11 , V_10 ) ;
return V_10 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
F_2 ( L_1 , V_11 ) ;
if ( V_2 -> V_31 != V_2 -> V_32 ||
memcmp ( V_2 -> V_33 , V_2 -> V_34 ,
V_2 -> V_32 ) != 0 )
goto V_35;
if ( V_2 -> V_4 -> V_36 [ 0 ] || V_2 -> V_4 -> V_36 [ 1 ] ) {
bool V_37 = F_17 ( V_2 -> V_38 , V_2 -> V_4 -> V_36 [ 1 ] ) ;
bool V_39 = F_17 ( V_2 -> V_40 , V_2 -> V_4 -> V_36 [ 0 ] ) ;
if ( ! V_37 && ! V_39 )
goto V_35;
V_10 = - V_41 ;
if ( ( ( V_37 && ! V_39 ) || ( V_39 && ! V_37 ) ) &&
V_2 -> V_4 -> V_36 [ 0 ] && V_2 -> V_4 -> V_36 [ 1 ] )
goto V_42;
}
V_10 = - V_41 ;
if ( V_2 -> V_12 -> V_13 != V_2 -> V_4 -> V_13 )
goto V_42;
V_10 = F_18 ( V_2 -> V_12 , V_2 -> V_4 ) ;
if ( V_10 < 0 ) {
if ( V_10 == - V_43 ) {
V_2 -> V_15 = true ;
V_10 = 0 ;
}
goto V_42;
}
F_2 ( L_3 ) ;
V_2 -> V_44 = true ;
V_42:
F_2 ( L_2 , V_11 , V_10 ) ;
return V_10 ;
V_35:
F_2 ( L_4 , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
const char * V_49 ;
T_1 V_50 , V_51 ;
char * V_8 = NULL , * V_52 ;
int V_10 ;
V_2 = F_20 ( V_46 -> V_53 , V_46 -> V_54 ) ;
if ( F_5 ( V_2 ) )
return F_6 ( V_2 ) ;
F_2 ( L_5 , V_2 -> V_55 ) ;
F_2 ( L_6 , V_2 -> V_56 ) ;
if ( V_2 -> V_14 ) {
V_10 = - V_43 ;
goto V_57;
}
F_2 ( L_7 , V_2 -> V_12 -> V_13 ) ;
F_2 ( L_8 , V_2 -> V_58 , V_2 -> V_59 ) ;
V_2 -> V_12 -> V_60 = L_9 ;
if ( V_2 -> V_15 ) {
F_21 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
} else {
F_2 ( L_10 ,
V_2 -> V_4 -> V_13 , V_2 -> V_4 -> V_16 ) ;
}
V_51 = strlen ( V_2 -> V_56 ) ;
if ( V_2 -> V_61 ) {
V_50 = V_2 -> V_62 ;
V_49 = V_2 -> V_61 ;
} else {
V_50 = V_2 -> V_63 ;
V_49 = V_2 -> V_64 ;
}
V_10 = - V_21 ;
V_8 = F_9 ( V_51 + 2 + V_50 * 2 + 1 , V_20 ) ;
if ( ! V_8 )
goto V_57;
V_52 = memcpy ( V_8 , V_2 -> V_56 , V_51 ) ;
V_52 += V_51 ;
* V_52 ++ = ':' ;
* V_52 ++ = ' ' ;
V_52 = F_22 ( V_52 , V_49 , V_50 ) ;
* V_52 = 0 ;
V_48 = F_9 ( sizeof( struct V_47 ) , V_20 ) ;
if ( ! V_48 )
goto V_65;
V_48 -> V_40 [ 0 ] = V_2 -> V_40 ;
V_48 -> V_40 [ 1 ] = V_2 -> V_38 ;
F_23 ( V_66 . V_67 ) ;
V_46 -> V_68 . V_53 [ V_69 ] = & V_66 ;
V_46 -> V_68 . V_53 [ V_70 ] = V_48 ;
V_46 -> V_68 . V_53 [ V_71 ] = V_2 -> V_12 ;
V_46 -> V_68 . V_53 [ V_72 ] = V_2 -> V_4 ;
V_46 -> V_73 = V_8 ;
V_46 -> V_74 = 100 ;
V_2 -> V_12 = NULL ;
V_2 -> V_40 = NULL ;
V_2 -> V_38 = NULL ;
V_2 -> V_4 = NULL ;
V_8 = NULL ;
V_10 = 0 ;
V_65:
F_14 ( V_8 ) ;
V_57:
F_24 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_75 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_75 ) ;
}
