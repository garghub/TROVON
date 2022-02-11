static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 -> V_7 ) ;
}
F_5 ( & V_8 ) ;
V_9 [ V_4 -> V_10 . V_11 ] = NULL ;
F_6 ( & V_8 ) ;
F_4 ( V_4 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_12 = 0 ;
int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
struct V_16 * V_10 = & V_4 -> V_10 ;
V_13 = F_8 ( V_10 -> V_17 ) +
( V_10 -> V_17 % 8 ? 1 : 0 ) ;
V_15 = V_10 -> V_15 ? V_10 -> V_15 : V_18 / V_13 ;
V_14 = V_10 -> V_14 ? V_10 -> V_14 : V_13 ;
if ( V_10 -> V_19 ) {
V_4 -> V_7 = V_10 -> V_19 ;
V_4 -> V_6 = false ;
} else {
V_4 -> V_7 = F_9 ( sizeof( struct V_20 ) , V_21 ) ;
if ( ! V_4 -> V_7 ) {
V_12 = - V_22 ;
goto V_23;
}
V_12 = F_10 ( V_4 -> V_7 , V_14 , V_15 ) ;
if ( V_12 ) {
F_4 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
goto V_23;
}
V_4 -> V_6 = true ;
V_10 -> V_19 = V_4 -> V_7 ;
}
V_4 -> V_14 = V_4 -> V_7 -> V_14 ;
V_23:
return V_12 ;
}
int F_11 ( struct V_16 * V_10 )
{
struct V_3 * V_4 ;
int V_11 ;
int V_12 ;
if ( ! V_10 ) {
F_12 ( L_1 ) ;
return - V_24 ;
}
if ( ! V_10 -> V_5 ) {
F_12 ( L_2 ) ;
return - V_25 ;
}
if ( ! V_10 -> V_26 ) {
F_12 ( L_3 ) ;
return - V_25 ;
}
if ( V_10 -> V_11 >= V_27 ) {
F_13 ( V_10 -> V_5 , L_4 ,
V_27 - 1 ) ;
return - V_24 ;
}
if ( V_10 -> V_17 < 1 || V_10 -> V_17 > ( V_18 * 8 ) ) {
F_13 ( V_10 -> V_5 , L_5 ,
V_18 * 8 ) ;
return - V_24 ;
}
if ( ! V_10 -> V_19 && ! ( V_10 -> V_26 && V_10 -> V_26 -> V_28 &&
V_10 -> V_26 -> V_29 && V_10 -> V_26 -> V_30 ) ) {
F_13 ( V_10 -> V_5 , L_6 ) ;
return - V_24 ;
}
F_5 ( & V_8 ) ;
V_11 = V_10 -> V_11 ;
if ( V_11 < 0 ) {
for ( V_11 = 0 ; V_11 < V_27 ; V_11 ++ )
if ( ! V_9 [ V_11 ] )
break;
if ( V_11 == V_27 ) {
F_13 ( V_10 -> V_5 , L_7 ) ;
V_12 = - V_22 ;
goto V_31;
}
} else if ( V_9 [ V_11 ] ) {
F_13 ( V_10 -> V_5 , L_8 , V_11 ) ;
V_12 = - V_32 ;
goto V_31;
}
V_4 = F_14 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 ) {
V_12 = - V_22 ;
goto V_31;
}
F_15 ( & V_4 -> V_33 ) ;
V_9 [ V_11 ] = V_4 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_34 [ sizeof( V_10 -> V_34 ) - 1 ] = '\0' ;
if ( V_10 -> V_35 == 0 )
V_10 -> V_35 = V_36 ;
V_4 -> V_10 = * V_10 ;
if ( F_16 ( V_10 -> V_35 ) ) {
V_12 = F_7 ( V_9 [ V_11 ] ) ;
if ( V_12 ) {
F_4 ( V_4 ) ;
goto V_31;
}
V_10 -> V_19 = V_4 -> V_7 ;
}
F_17 ( & V_4 -> V_5 ) ;
V_4 -> V_5 . V_37 = F_18 ( F_19 ( V_38 ) , V_4 -> V_10 . V_11 ) ;
V_4 -> V_5 . V_39 = V_40 ;
V_4 -> V_5 . V_41 = V_10 -> V_5 ;
V_4 -> V_5 . V_42 = F_1 ;
F_20 ( & V_4 -> V_5 , L_9 , V_4 -> V_10 . V_11 ) ;
F_21 ( & V_4 -> V_43 , V_10 -> V_26 ) ;
V_4 -> V_43 . V_44 = V_4 -> V_10 . V_44 ;
V_4 -> V_43 . V_45 . V_41 = & V_4 -> V_5 . V_45 ;
V_12 = F_22 ( & V_4 -> V_43 , V_4 -> V_5 . V_37 , 1 ) ;
if ( V_12 )
goto V_46;
V_4 -> V_47 = 1 ;
V_12 = F_23 ( & V_4 -> V_5 ) ;
if ( V_12 )
goto V_48;
F_6 ( & V_8 ) ;
F_24 ( V_4 -> V_10 . V_5 , L_10 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
return V_11 ;
V_48:
F_25 ( & V_4 -> V_43 ) ;
V_46:
F_26 ( & V_4 -> V_5 ) ;
V_31:
F_6 ( & V_8 ) ;
return V_12 ;
}
int F_27 ( int V_11 )
{
struct V_3 * V_4 ;
if ( V_11 < 0 || V_11 >= V_27 ) {
F_12 ( L_11 ,
V_11 , V_27 - 1 ) ;
return - V_24 ;
}
V_4 = V_9 [ V_11 ] ;
if ( ! V_4 ) {
F_12 ( L_12 ) ;
return - V_49 ;
}
F_5 ( & V_8 ) ;
if ( V_4 -> V_10 . V_11 != V_11 ) {
F_13 ( V_4 -> V_10 . V_5 , L_13 ,
V_11 ) ;
F_6 ( & V_8 ) ;
return - V_49 ;
}
F_28 ( V_4 -> V_10 . V_5 , L_14 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
V_4 -> V_47 = 0 ;
if ( V_4 -> V_50 ) {
F_28 ( V_4 -> V_10 . V_5 , V_51 L_15 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
F_29 ( & V_4 -> V_7 -> V_52 ) ;
}
F_6 ( & V_8 ) ;
F_30 ( & V_4 -> V_5 ) ;
F_25 ( & V_4 -> V_43 ) ;
F_26 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_31 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
struct V_3 * V_4 ;
int V_55 = 0 ;
if ( F_32 ( V_53 ) >= V_27 ) {
F_12 ( L_16 , F_32 ( V_53 ) ) ;
return - V_56 ;
}
if ( F_33 ( & V_8 ) )
return - V_57 ;
V_4 = V_9 [ F_32 ( V_53 ) ] ;
F_6 ( & V_8 ) ;
if ( ! V_4 ) {
V_55 = - V_56 ;
goto error;
}
F_28 ( V_4 -> V_10 . V_5 , V_51 L_17 , V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
if ( V_4 -> V_10 . V_11 == V_58 ) {
V_55 = - V_56 ;
goto error;
}
if ( V_4 -> V_50 ) {
V_55 = - V_32 ;
goto error;
}
if ( V_4 -> V_10 . V_59 ) {
V_55 = F_34 ( V_4 -> V_10 . V_59 ) ;
if ( V_55 )
goto error;
}
if ( V_4 -> V_7 )
F_35 ( V_4 -> V_7 ) ;
V_4 -> V_50 ++ ;
error:
F_36 ( V_53 , V_54 ) ;
return V_55 ;
}
int F_37 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
struct V_3 * V_4 = V_9 [ F_32 ( V_53 ) ] ;
int V_60 ;
if ( ! V_4 ) {
F_12 ( L_18 ) ;
return - V_25 ;
}
V_60 = F_38 ( & V_8 ) ;
F_39 ( V_60 ) ;
F_40 ( V_4 -> V_10 . V_59 ) ;
V_4 -> V_50 -- ;
if ( ! V_60 )
F_6 ( & V_8 ) ;
return 0 ;
}
unsigned int F_41 ( struct V_54 * V_54 , T_1 * V_61 )
{
struct V_3 * V_4 = V_9 [ F_32 ( F_42 ( V_54 ) ) ] ;
unsigned int V_60 ;
if ( ! V_4 ) {
F_12 ( L_18 ) ;
return V_62 ;
}
if ( ! V_4 -> V_47 )
return V_63 | V_62 ;
if ( V_4 -> V_7 ) {
F_43 ( V_54 , & V_4 -> V_7 -> V_52 , V_61 ) ;
if ( F_44 ( V_4 -> V_7 ) )
V_60 = 0 ;
else
V_60 = V_64 | V_65 ;
} else
V_60 = V_62 ;
F_28 ( V_4 -> V_10 . V_5 , V_51 L_19 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 , V_60 ) ;
return V_60 ;
}
long F_45 ( struct V_54 * V_54 , unsigned int V_66 , unsigned long V_67 )
{
T_2 V_68 ;
int V_69 = 0 ;
struct V_3 * V_4 = V_9 [ F_32 ( F_42 ( V_54 ) ) ] ;
if ( ! V_4 ) {
F_12 ( L_20 ) ;
return - V_56 ;
}
F_28 ( V_4 -> V_10 . V_5 , V_51 L_21 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 , V_66 ) ;
if ( V_4 -> V_10 . V_11 == V_58 || ! V_4 -> V_47 ) {
F_13 ( V_4 -> V_10 . V_5 , V_51 L_22 ,
V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
return - V_56 ;
}
F_5 ( & V_4 -> V_33 ) ;
switch ( V_66 ) {
case V_70 :
V_69 = F_46 ( V_4 -> V_10 . V_35 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_72 :
if ( ! F_16 ( V_4 -> V_10 . V_35 ) ) {
V_69 = - V_73 ;
break;
}
V_69 = F_46 ( F_47
( V_4 -> V_10 . V_35 & V_74 ) ,
( T_2 V_71 * ) V_67 ) ;
break;
case V_75 :
if ( ! F_16 ( V_4 -> V_10 . V_35 ) ) {
V_69 = - V_73 ;
break;
}
V_69 = F_48 ( V_68 , ( T_2 V_71 * ) V_67 ) ;
if ( ! V_69 && ! ( F_49 ( V_68 ) & V_4 -> V_10 . V_35 ) )
V_69 = - V_25 ;
break;
case V_76 :
V_69 = F_46 ( V_4 -> V_10 . V_17 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_77 :
if ( ! ( V_4 -> V_10 . V_35 & V_78 ) ||
V_4 -> V_10 . V_79 == 0 ) {
V_69 = - V_73 ;
break;
}
V_69 = F_46 ( V_4 -> V_10 . V_79 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_80 :
if ( ! ( V_4 -> V_10 . V_35 & V_78 ) ||
V_4 -> V_10 . V_81 == 0 ) {
V_69 = - V_73 ;
break;
}
V_69 = F_46 ( V_4 -> V_10 . V_81 , ( T_2 V_71 * ) V_67 ) ;
break;
default:
V_69 = - V_73 ;
}
F_6 ( & V_4 -> V_33 ) ;
return V_69 ;
}
T_3 F_50 ( struct V_54 * V_54 ,
char V_71 * V_82 ,
T_4 V_83 ,
T_5 * V_84 )
{
struct V_3 * V_4 = V_9 [ F_32 ( F_42 ( V_54 ) ) ] ;
unsigned char * V_7 ;
int V_60 = 0 , V_85 = 0 ;
F_51 ( V_61 , V_86 ) ;
if ( ! V_4 ) {
F_12 ( L_18 ) ;
return - V_56 ;
}
if ( ! F_16 ( V_4 -> V_10 . V_35 ) )
return - V_25 ;
F_28 ( V_4 -> V_10 . V_5 , V_51 L_23 , V_4 -> V_10 . V_34 , V_4 -> V_10 . V_11 ) ;
V_7 = F_14 ( V_4 -> V_14 , V_21 ) ;
if ( ! V_7 )
return - V_22 ;
if ( F_33 ( & V_4 -> V_33 ) ) {
V_60 = - V_57 ;
goto V_87;
}
if ( ! V_4 -> V_47 ) {
V_60 = - V_56 ;
goto V_88;
}
if ( V_83 % V_4 -> V_14 ) {
V_60 = - V_25 ;
goto V_88;
}
F_52 ( & V_4 -> V_7 -> V_52 , & V_61 ) ;
while ( V_85 < V_83 && V_60 == 0 ) {
if ( F_44 ( V_4 -> V_7 ) ) {
if ( V_85 )
break;
if ( V_54 -> V_89 & V_90 ) {
V_60 = - V_91 ;
break;
}
if ( F_53 ( V_86 ) ) {
V_60 = - V_57 ;
break;
}
F_6 ( & V_4 -> V_33 ) ;
F_54 ( V_92 ) ;
F_55 () ;
F_54 ( V_93 ) ;
if ( F_33 ( & V_4 -> V_33 ) ) {
V_60 = - V_57 ;
F_56 ( & V_4 -> V_7 -> V_52 , & V_61 ) ;
goto V_87;
}
if ( ! V_4 -> V_47 ) {
V_60 = - V_56 ;
goto V_88;
}
} else {
F_57 ( V_4 -> V_7 , V_7 ) ;
V_60 = F_58 ( ( void V_71 * ) V_82 + V_85 , V_7 ,
V_4 -> V_7 -> V_14 ) ;
if ( ! V_60 )
V_85 += V_4 -> V_7 -> V_14 ;
else
V_60 = - V_94 ;
}
}
F_56 ( & V_4 -> V_7 -> V_52 , & V_61 ) ;
V_88:
F_6 ( & V_4 -> V_33 ) ;
V_87:
F_4 ( V_7 ) ;
return V_60 ? V_60 : V_85 ;
}
void * F_59 ( struct V_54 * V_54 )
{
return V_9 [ F_32 ( F_42 ( V_54 ) ) ] -> V_10 . V_95 ;
}
static int T_6 F_60 ( void )
{
int V_55 ;
V_40 = F_61 ( V_96 , L_24 ) ;
if ( F_62 ( V_40 ) ) {
F_12 ( L_25 ) ;
return F_63 ( V_40 ) ;
}
V_55 = F_64 ( & V_38 , 0 , V_27 ,
L_26 ) ;
if ( V_55 ) {
F_65 ( V_40 ) ;
F_12 ( L_27 ) ;
return V_55 ;
}
F_66 ( L_28 ,
F_19 ( V_38 ) ) ;
return 0 ;
}
static void T_7 F_67 ( void )
{
F_65 ( V_40 ) ;
F_68 ( V_38 , V_27 ) ;
F_66 ( L_29 ) ;
}
