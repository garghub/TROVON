static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_5 . V_6 ) ;
if ( V_4 -> V_7 ) {
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_8 ) ;
}
F_6 ( & V_9 ) ;
V_10 [ V_4 -> V_11 . V_12 ] = NULL ;
F_7 ( & V_9 ) ;
F_5 ( V_4 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_13 = 0 ;
int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
struct V_17 * V_11 = & V_4 -> V_11 ;
V_14 = F_9 ( V_11 -> V_18 ) +
( V_11 -> V_18 % 8 ? 1 : 0 ) ;
V_16 = V_11 -> V_16 ? V_11 -> V_16 : V_19 / V_14 ;
V_15 = V_11 -> V_15 ? V_11 -> V_15 : V_14 ;
if ( V_11 -> V_20 ) {
V_4 -> V_8 = V_11 -> V_20 ;
V_4 -> V_7 = false ;
} else {
V_4 -> V_8 = F_10 ( sizeof( struct V_21 ) , V_22 ) ;
if ( ! V_4 -> V_8 ) {
V_13 = - V_23 ;
goto V_24;
}
V_13 = F_11 ( V_4 -> V_8 , V_15 , V_16 ) ;
if ( V_13 ) {
F_5 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
goto V_24;
}
V_4 -> V_7 = true ;
V_11 -> V_20 = V_4 -> V_8 ;
}
V_4 -> V_15 = V_4 -> V_8 -> V_15 ;
V_24:
return V_13 ;
}
int F_12 ( struct V_17 * V_11 )
{
struct V_3 * V_4 ;
int V_12 ;
int V_13 ;
if ( ! V_11 ) {
F_13 ( L_1 ) ;
return - V_25 ;
}
if ( ! V_11 -> V_5 ) {
F_13 ( L_2 ) ;
return - V_26 ;
}
if ( ! V_11 -> V_27 ) {
F_13 ( L_3 ) ;
return - V_26 ;
}
if ( V_11 -> V_12 >= V_28 ) {
F_14 ( V_11 -> V_5 , L_4 ,
V_28 - 1 ) ;
return - V_25 ;
}
if ( V_11 -> V_18 < 1 || V_11 -> V_18 > ( V_19 * 8 ) ) {
F_14 ( V_11 -> V_5 , L_5 ,
V_19 * 8 ) ;
return - V_25 ;
}
if ( ! V_11 -> V_20 && ! ( V_11 -> V_27 && V_11 -> V_27 -> V_29 &&
V_11 -> V_27 -> V_30 && V_11 -> V_27 -> V_31 ) ) {
F_14 ( V_11 -> V_5 , L_6 ) ;
return - V_25 ;
}
F_6 ( & V_9 ) ;
V_12 = V_11 -> V_12 ;
if ( V_12 < 0 ) {
for ( V_12 = 0 ; V_12 < V_28 ; V_12 ++ )
if ( ! V_10 [ V_12 ] )
break;
if ( V_12 == V_28 ) {
F_14 ( V_11 -> V_5 , L_7 ) ;
V_13 = - V_23 ;
goto V_32;
}
} else if ( V_10 [ V_12 ] ) {
F_14 ( V_11 -> V_5 , L_8 , V_12 ) ;
V_13 = - V_33 ;
goto V_32;
}
V_4 = F_15 ( sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_4 ) {
V_13 = - V_23 ;
goto V_32;
}
F_16 ( & V_4 -> V_34 ) ;
V_10 [ V_12 ] = V_4 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_35 [ sizeof( V_11 -> V_35 ) - 1 ] = '\0' ;
if ( V_11 -> V_36 == 0 )
V_11 -> V_36 = V_37 ;
V_4 -> V_11 = * V_11 ;
if ( F_17 ( V_11 -> V_36 ) ) {
V_13 = F_8 ( V_10 [ V_12 ] ) ;
if ( V_13 ) {
F_5 ( V_4 ) ;
goto V_32;
}
V_11 -> V_20 = V_4 -> V_8 ;
}
F_18 ( & V_4 -> V_5 ) ;
V_4 -> V_5 . V_38 = F_19 ( F_20 ( V_39 ) , V_4 -> V_11 . V_12 ) ;
V_4 -> V_5 . V_40 = V_41 ;
V_4 -> V_5 . V_6 = V_11 -> V_5 ;
V_4 -> V_5 . V_42 = F_1 ;
F_21 ( & V_4 -> V_5 , L_9 , V_4 -> V_11 . V_12 ) ;
F_22 ( & V_4 -> V_43 , V_11 -> V_27 ) ;
V_4 -> V_43 . V_44 = V_4 -> V_11 . V_44 ;
V_4 -> V_43 . V_45 . V_6 = & V_4 -> V_5 . V_45 ;
V_13 = F_23 ( & V_4 -> V_43 , V_4 -> V_5 . V_38 , 1 ) ;
if ( V_13 )
goto V_46;
V_4 -> V_47 = 1 ;
V_13 = F_24 ( & V_4 -> V_5 ) ;
if ( V_13 )
goto V_48;
F_7 ( & V_9 ) ;
F_25 ( V_4 -> V_5 . V_6 ) ;
F_26 ( V_4 -> V_11 . V_5 , L_10 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
return V_12 ;
V_48:
F_27 ( & V_4 -> V_43 ) ;
V_46:
F_3 ( & V_4 -> V_5 ) ;
V_32:
F_7 ( & V_9 ) ;
return V_13 ;
}
int F_28 ( int V_12 )
{
struct V_3 * V_4 ;
if ( V_12 < 0 || V_12 >= V_28 ) {
F_13 ( L_11 ,
V_12 , V_28 - 1 ) ;
return - V_25 ;
}
V_4 = V_10 [ V_12 ] ;
if ( ! V_4 ) {
F_13 ( L_12 ) ;
return - V_49 ;
}
F_6 ( & V_9 ) ;
if ( V_4 -> V_11 . V_12 != V_12 ) {
F_14 ( V_4 -> V_11 . V_5 , L_13 ,
V_12 ) ;
F_7 ( & V_9 ) ;
return - V_49 ;
}
F_29 ( V_4 -> V_11 . V_5 , L_14 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
V_4 -> V_47 = 0 ;
if ( V_4 -> V_50 ) {
F_29 ( V_4 -> V_11 . V_5 , V_51 L_15 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
F_30 ( & V_4 -> V_8 -> V_52 ) ;
}
F_7 ( & V_9 ) ;
F_31 ( & V_4 -> V_5 ) ;
F_27 ( & V_4 -> V_43 ) ;
F_3 ( & V_4 -> V_5 ) ;
return 0 ;
}
int F_32 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
struct V_3 * V_4 ;
int V_55 = 0 ;
if ( F_33 ( V_53 ) >= V_28 ) {
F_13 ( L_16 , F_33 ( V_53 ) ) ;
return - V_56 ;
}
if ( F_34 ( & V_9 ) )
return - V_57 ;
V_4 = V_10 [ F_33 ( V_53 ) ] ;
F_7 ( & V_9 ) ;
if ( ! V_4 ) {
V_55 = - V_56 ;
goto error;
}
F_29 ( V_4 -> V_11 . V_5 , V_51 L_17 , V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
if ( V_4 -> V_11 . V_12 == V_58 ) {
V_55 = - V_56 ;
goto error;
}
if ( V_4 -> V_50 ) {
V_55 = - V_33 ;
goto error;
}
if ( V_4 -> V_11 . V_59 ) {
V_55 = F_35 ( V_4 -> V_11 . V_59 ) ;
if ( V_55 )
goto error;
}
if ( V_4 -> V_8 )
F_36 ( V_4 -> V_8 ) ;
V_4 -> V_50 ++ ;
error:
F_37 ( V_53 , V_54 ) ;
return V_55 ;
}
int F_38 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
struct V_3 * V_4 = V_10 [ F_33 ( V_53 ) ] ;
int V_60 ;
if ( ! V_4 ) {
F_13 ( L_18 ) ;
return - V_26 ;
}
V_60 = F_39 ( & V_9 ) ;
F_40 ( V_60 ) ;
F_41 ( V_4 -> V_11 . V_59 ) ;
V_4 -> V_50 -- ;
if ( ! V_60 )
F_7 ( & V_9 ) ;
return 0 ;
}
unsigned int F_42 ( struct V_54 * V_54 , T_1 * V_61 )
{
struct V_3 * V_4 = V_10 [ F_33 ( F_43 ( V_54 ) ) ] ;
unsigned int V_60 ;
if ( ! V_4 ) {
F_13 ( L_18 ) ;
return V_62 ;
}
if ( ! V_4 -> V_47 )
return V_63 | V_62 ;
if ( V_4 -> V_8 ) {
F_44 ( V_54 , & V_4 -> V_8 -> V_52 , V_61 ) ;
if ( F_45 ( V_4 -> V_8 ) )
V_60 = 0 ;
else
V_60 = V_64 | V_65 ;
} else
V_60 = V_62 ;
F_29 ( V_4 -> V_11 . V_5 , V_51 L_19 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 , V_60 ) ;
return V_60 ;
}
long F_46 ( struct V_54 * V_54 , unsigned int V_66 , unsigned long V_67 )
{
T_2 V_68 ;
int V_69 = 0 ;
struct V_3 * V_4 = V_10 [ F_33 ( F_43 ( V_54 ) ) ] ;
if ( ! V_4 ) {
F_13 ( L_20 ) ;
return - V_56 ;
}
F_29 ( V_4 -> V_11 . V_5 , V_51 L_21 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 , V_66 ) ;
if ( V_4 -> V_11 . V_12 == V_58 || ! V_4 -> V_47 ) {
F_14 ( V_4 -> V_11 . V_5 , V_51 L_22 ,
V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
return - V_56 ;
}
F_6 ( & V_4 -> V_34 ) ;
switch ( V_66 ) {
case V_70 :
V_69 = F_47 ( V_4 -> V_11 . V_36 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_72 :
if ( ! F_17 ( V_4 -> V_11 . V_36 ) ) {
V_69 = - V_73 ;
break;
}
V_69 = F_47 ( F_48
( V_4 -> V_11 . V_36 & V_74 ) ,
( T_2 V_71 * ) V_67 ) ;
break;
case V_75 :
if ( ! F_17 ( V_4 -> V_11 . V_36 ) ) {
V_69 = - V_73 ;
break;
}
V_69 = F_49 ( V_68 , ( T_2 V_71 * ) V_67 ) ;
if ( ! V_69 && ! ( F_50 ( V_68 ) & V_4 -> V_11 . V_36 ) )
V_69 = - V_26 ;
break;
case V_76 :
V_69 = F_47 ( V_4 -> V_11 . V_18 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_77 :
if ( ! ( V_4 -> V_11 . V_36 & V_78 ) ||
V_4 -> V_11 . V_79 == 0 ) {
V_69 = - V_73 ;
break;
}
V_69 = F_47 ( V_4 -> V_11 . V_79 , ( T_2 V_71 * ) V_67 ) ;
break;
case V_80 :
if ( ! ( V_4 -> V_11 . V_36 & V_78 ) ||
V_4 -> V_11 . V_81 == 0 ) {
V_69 = - V_73 ;
break;
}
V_69 = F_47 ( V_4 -> V_11 . V_81 , ( T_2 V_71 * ) V_67 ) ;
break;
default:
V_69 = - V_73 ;
}
F_7 ( & V_4 -> V_34 ) ;
return V_69 ;
}
T_3 F_51 ( struct V_54 * V_54 ,
char V_71 * V_82 ,
T_4 V_83 ,
T_5 * V_84 )
{
struct V_3 * V_4 = V_10 [ F_33 ( F_43 ( V_54 ) ) ] ;
unsigned char * V_8 ;
int V_60 = 0 , V_85 = 0 ;
F_52 ( V_61 , V_86 ) ;
if ( ! V_4 ) {
F_13 ( L_18 ) ;
return - V_56 ;
}
if ( ! F_17 ( V_4 -> V_11 . V_36 ) )
return - V_26 ;
F_29 ( V_4 -> V_11 . V_5 , V_51 L_23 , V_4 -> V_11 . V_35 , V_4 -> V_11 . V_12 ) ;
V_8 = F_15 ( V_4 -> V_15 , V_22 ) ;
if ( ! V_8 )
return - V_23 ;
if ( F_34 ( & V_4 -> V_34 ) ) {
V_60 = - V_57 ;
goto V_87;
}
if ( ! V_4 -> V_47 ) {
V_60 = - V_56 ;
goto V_88;
}
if ( V_83 % V_4 -> V_15 ) {
V_60 = - V_26 ;
goto V_88;
}
F_53 ( & V_4 -> V_8 -> V_52 , & V_61 ) ;
while ( V_85 < V_83 && V_60 == 0 ) {
if ( F_45 ( V_4 -> V_8 ) ) {
if ( V_85 )
break;
if ( V_54 -> V_89 & V_90 ) {
V_60 = - V_91 ;
break;
}
if ( F_54 ( V_86 ) ) {
V_60 = - V_57 ;
break;
}
F_7 ( & V_4 -> V_34 ) ;
F_55 ( V_92 ) ;
F_56 () ;
F_55 ( V_93 ) ;
if ( F_34 ( & V_4 -> V_34 ) ) {
V_60 = - V_57 ;
F_57 ( & V_4 -> V_8 -> V_52 , & V_61 ) ;
goto V_87;
}
if ( ! V_4 -> V_47 ) {
V_60 = - V_56 ;
goto V_88;
}
} else {
F_58 ( V_4 -> V_8 , V_8 ) ;
V_60 = F_59 ( ( void V_71 * ) V_82 + V_85 , V_8 ,
V_4 -> V_8 -> V_15 ) ;
if ( ! V_60 )
V_85 += V_4 -> V_8 -> V_15 ;
else
V_60 = - V_94 ;
}
}
F_57 ( & V_4 -> V_8 -> V_52 , & V_61 ) ;
V_88:
F_7 ( & V_4 -> V_34 ) ;
V_87:
F_5 ( V_8 ) ;
return V_60 ? V_60 : V_85 ;
}
void * F_60 ( struct V_54 * V_54 )
{
return V_10 [ F_33 ( F_43 ( V_54 ) ) ] -> V_11 . V_95 ;
}
static int T_6 F_61 ( void )
{
int V_55 ;
V_41 = F_62 ( V_96 , L_24 ) ;
if ( F_63 ( V_41 ) ) {
F_13 ( L_25 ) ;
return F_64 ( V_41 ) ;
}
V_55 = F_65 ( & V_39 , 0 , V_28 ,
L_26 ) ;
if ( V_55 ) {
F_66 ( V_41 ) ;
F_13 ( L_27 ) ;
return V_55 ;
}
F_67 ( L_28 ,
F_20 ( V_39 ) ) ;
return 0 ;
}
static void T_7 F_68 ( void )
{
F_66 ( V_41 ) ;
F_69 ( V_39 , V_28 ) ;
F_67 ( L_29 ) ;
}
