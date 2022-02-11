static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_5 = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_7 , F_5 ( F_6 ( V_8 ) , V_2 -> V_4 . V_5 ) ) ;
if ( V_2 -> V_9 != V_2 -> V_4 . V_10 ) {
F_7 ( V_2 -> V_9 ) ;
F_8 ( V_2 -> V_9 ) ;
}
V_2 -> V_9 = NULL ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_11 ;
int V_12 = - 1 ;
if ( ! V_2 -> V_4 . V_13 )
return 0 ;
do {
V_12 ++ ;
V_11 = V_2 -> V_4 . V_13 ( V_2 -> V_4 . V_14 , V_2 -> V_9 ) ;
} while ( ! V_11 );
if ( V_11 == - V_15 )
F_10 ( V_2 -> V_16 ) ;
return V_12 ? 0 : V_11 ;
}
static int F_11 ( void * V_1 )
{
struct V_1 * V_2 = V_1 ;
do {
if ( V_2 -> V_17 ) {
if ( V_2 -> V_18 ) {
F_12 ( V_19 ) ;
F_13 ( V_2 -> V_18 ) ;
}
if ( F_14 () )
break;
if ( ! F_9 ( V_2 ) )
F_15 ( & V_2 -> V_9 -> V_20 ) ;
} else {
F_12 ( V_19 ) ;
F_16 () ;
}
} while ( ! F_14 () );
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_21 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_22 ;
int V_23 ;
V_22 = F_18 () ;
if ( ! V_22 )
return - V_24 ;
if ( V_4 -> V_25 ) {
V_22 -> V_26 = V_4 -> V_25 ;
V_22 -> V_27 = V_4 -> V_27 ;
} else {
V_22 -> V_26 = & V_28 ;
V_22 -> V_27 = V_29 ;
}
V_23 = F_19 ( & V_22 -> V_30 , L_1 , V_4 -> V_5 ) ;
if ( V_23 )
goto V_31;
V_23 = F_20 ( V_22 , F_5 ( F_6 ( V_8 ) , V_4 -> V_5 ) , 1 ) ;
if ( V_23 )
goto V_31;
V_2 -> V_22 = V_22 ;
return 0 ;
V_31:
F_21 ( V_22 ) ;
return V_23 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
int V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
struct V_21 * V_4 = & V_2 -> V_4 ;
F_23 ( & V_36 ) ;
V_33 = F_24 ( V_4 -> V_37 ) +
( V_4 -> V_37 % 8 ? 1 : 0 ) ;
V_35 = V_4 -> V_35 ? V_4 -> V_35 : V_38 / V_33 ;
V_34 = V_4 -> V_34 ? V_4 -> V_34 : V_33 ;
if ( V_4 -> V_10 ) {
V_2 -> V_9 = V_4 -> V_10 ;
} else {
V_2 -> V_9 = F_25 ( sizeof( struct V_39 ) , V_40 ) ;
if ( ! V_2 -> V_9 ) {
V_32 = - V_24 ;
goto V_41;
}
V_32 = F_26 ( V_2 -> V_9 , V_34 , V_35 ) ;
if ( V_32 ) {
F_8 ( V_2 -> V_9 ) ;
goto V_41;
}
}
V_2 -> V_34 = V_2 -> V_9 -> V_34 ;
V_41:
F_27 ( & V_36 ) ;
return V_32 ;
}
static int F_28 ( struct V_21 * V_4 )
{
struct V_1 * V_2 ;
int V_5 ;
int V_32 ;
if ( ! V_4 ) {
F_29 ( L_2 ) ;
return - V_42 ;
}
if ( ! V_4 -> V_43 ) {
F_29 ( L_3 ) ;
return - V_44 ;
}
if ( V_4 -> V_5 >= V_45 ) {
F_30 ( V_4 -> V_43 , L_4 ,
V_45 - 1 ) ;
return - V_42 ;
}
if ( V_4 -> V_37 < 1 || V_4 -> V_37 > ( V_38 * 8 ) ) {
F_30 ( V_4 -> V_43 , L_5 ,
V_38 * 8 ) ;
return - V_42 ;
}
if ( V_4 -> V_46 ) {
if ( 2 > V_4 -> V_46 || V_47 < V_4 -> V_46 ) {
F_30 ( V_4 -> V_43 , L_6 ,
V_4 -> V_46 ) ;
return - V_42 ;
}
if ( ! V_4 -> V_13 ) {
F_30 ( V_4 -> V_43 , L_7 ) ;
return - V_42 ;
}
} else if ( ! V_4 -> V_10 && ! ( V_4 -> V_25 && V_4 -> V_25 -> V_48 &&
V_4 -> V_25 -> V_49 && V_4 -> V_25 -> V_50 ) ) {
F_30 ( V_4 -> V_43 , L_8 ) ;
return - V_42 ;
}
F_23 ( & V_36 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 < 0 ) {
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ )
if ( ! V_51 [ V_5 ] )
break;
if ( V_5 == V_45 ) {
F_30 ( V_4 -> V_43 , L_9 ) ;
V_32 = - V_24 ;
goto V_52;
}
} else if ( V_51 [ V_5 ] ) {
F_30 ( V_4 -> V_43 , L_10 , V_5 ) ;
V_32 = - V_53 ;
goto V_52;
}
V_2 = F_31 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 ) {
V_32 = - V_24 ;
goto V_52;
}
F_1 ( V_2 ) ;
V_51 [ V_5 ] = V_2 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_54 [ sizeof( V_4 -> V_54 ) - 1 ] = '\0' ;
if ( V_4 -> V_55 == 0 )
V_4 -> V_55 = V_56 ;
V_2 -> V_4 = * V_4 ;
F_32 ( V_7 , V_2 -> V_4 . V_43 ,
F_5 ( F_6 ( V_8 ) , V_2 -> V_4 . V_5 ) , NULL ,
L_11 , V_2 -> V_4 . V_5 ) ;
if ( V_4 -> V_46 ) {
V_2 -> V_18 = V_47 / V_4 -> V_46 ;
V_2 -> V_16 = F_33 ( F_11 , ( void * ) V_2 , L_12 ) ;
if ( F_34 ( V_2 -> V_16 ) ) {
F_30 ( V_4 -> V_43 , L_13 ,
V_4 -> V_5 ) ;
V_32 = - V_57 ;
goto V_58;
}
} else {
V_2 -> V_18 = 0 ;
}
V_32 = F_17 ( V_2 ) ;
if ( V_32 )
goto V_58;
V_2 -> V_59 = 1 ;
F_27 ( & V_36 ) ;
F_35 ( V_2 -> V_4 . V_43 , L_14 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
return V_5 ;
V_58:
F_4 ( V_7 , F_5 ( F_6 ( V_8 ) , V_2 -> V_4 . V_5 ) ) ;
V_52:
F_27 ( & V_36 ) ;
return V_32 ;
}
int F_36 ( struct V_21 * V_4 )
{
int V_5 , V_32 = 0 ;
V_5 = F_28 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_37 ( V_4 -> V_55 ) ) {
V_32 = F_22 ( V_51 [ V_5 ] ) ;
if ( V_32 )
F_38 ( V_5 ) ;
}
return V_32 ? V_32 : V_5 ;
}
int F_38 ( int V_5 )
{
struct V_1 * V_2 ;
struct V_22 * V_22 ;
if ( V_5 < 0 || V_5 >= V_45 ) {
F_29 ( L_15 ,
V_5 , V_45 - 1 ) ;
return - V_42 ;
}
V_2 = V_51 [ V_5 ] ;
if ( ! V_2 ) {
F_29 ( L_16 ) ;
return - V_60 ;
}
V_22 = V_2 -> V_22 ;
F_23 ( & V_36 ) ;
if ( V_2 -> V_4 . V_5 != V_5 ) {
F_30 ( V_2 -> V_4 . V_43 , L_17 ,
V_5 ) ;
F_27 ( & V_36 ) ;
return - V_60 ;
}
if ( V_2 -> V_16 )
F_10 ( V_2 -> V_16 ) ;
F_39 ( V_2 -> V_4 . V_43 , L_18 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
V_2 -> V_59 = 0 ;
if ( V_2 -> V_17 ) {
F_39 ( V_2 -> V_4 . V_43 , V_61 L_19 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
F_15 ( & V_2 -> V_9 -> V_20 ) ;
F_23 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 . V_62 )
V_2 -> V_4 . V_62 ( V_2 -> V_4 . V_14 ) ;
F_40 ( V_22 -> V_27 ) ;
F_27 ( & V_2 -> V_3 ) ;
} else {
F_3 ( V_2 ) ;
F_21 ( V_22 ) ;
F_8 ( V_2 ) ;
V_51 [ V_5 ] = NULL ;
}
F_27 ( & V_36 ) ;
return 0 ;
}
int F_41 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int V_23 = 0 ;
if ( F_42 ( V_63 ) >= V_45 ) {
F_29 ( L_20 , F_42 ( V_63 ) ) ;
return - V_15 ;
}
if ( F_43 ( & V_36 ) )
return - V_65 ;
V_2 = V_51 [ F_42 ( V_63 ) ] ;
if ( ! V_2 ) {
V_23 = - V_15 ;
goto error;
}
F_39 ( V_2 -> V_4 . V_43 , V_61 L_21 , V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
if ( V_2 -> V_4 . V_5 == V_6 ) {
V_23 = - V_15 ;
goto error;
}
if ( V_2 -> V_17 ) {
V_23 = - V_53 ;
goto error;
}
if ( V_2 -> V_4 . V_66 ) {
V_23 = F_44 ( V_2 -> V_4 . V_66 ) ;
if ( V_23 )
goto error;
}
V_22 = V_2 -> V_22 ;
if ( F_45 ( V_22 -> V_27 ) ) {
V_2 -> V_17 ++ ;
if ( V_2 -> V_4 . V_67 )
V_23 = V_2 -> V_4 . V_67 ( V_2 -> V_4 . V_14 ) ;
if ( V_23 ) {
F_40 ( V_22 -> V_27 ) ;
V_2 -> V_17 -- ;
} else {
F_46 ( V_2 -> V_9 ) ;
}
if ( V_2 -> V_16 )
F_47 ( V_2 -> V_16 ) ;
}
error:
F_27 ( & V_36 ) ;
F_48 ( V_63 , V_64 ) ;
return V_23 ;
}
int F_49 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
struct V_1 * V_2 = V_51 [ F_42 ( V_63 ) ] ;
struct V_22 * V_22 ;
int V_68 ;
if ( ! V_2 ) {
F_29 ( L_22 ) ;
return - V_44 ;
}
V_22 = V_2 -> V_22 ;
V_68 = F_50 ( & V_36 ) ;
F_51 ( V_68 ) ;
F_52 ( V_2 -> V_4 . V_66 ) ;
V_2 -> V_17 -- ;
if ( V_2 -> V_59 ) {
if ( V_2 -> V_4 . V_62 )
V_2 -> V_4 . V_62 ( V_2 -> V_4 . V_14 ) ;
F_40 ( V_22 -> V_27 ) ;
} else {
F_3 ( V_2 ) ;
F_21 ( V_22 ) ;
V_51 [ V_2 -> V_4 . V_5 ] = NULL ;
F_8 ( V_2 ) ;
}
if ( ! V_68 )
F_27 ( & V_36 ) ;
return 0 ;
}
unsigned int F_53 ( struct V_64 * V_64 , T_1 * V_69 )
{
struct V_1 * V_2 = V_51 [ F_42 ( F_54 ( V_64 ) ) ] ;
unsigned int V_68 ;
if ( ! V_2 ) {
F_29 ( L_22 ) ;
return V_70 ;
}
if ( ! V_2 -> V_59 )
return V_70 ;
if ( V_2 -> V_9 ) {
F_55 ( V_64 , & V_2 -> V_9 -> V_20 , V_69 ) ;
if ( F_56 ( V_2 -> V_9 ) )
V_68 = 0 ;
else
V_68 = V_71 | V_72 ;
} else
V_68 = V_70 ;
F_39 ( V_2 -> V_4 . V_43 , V_61 L_23 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 , V_68 ) ;
return V_68 ;
}
long F_57 ( struct V_64 * V_64 , unsigned int V_73 , unsigned long V_74 )
{
T_2 V_75 ;
int V_76 = 0 ;
struct V_1 * V_2 = V_51 [ F_42 ( F_54 ( V_64 ) ) ] ;
if ( ! V_2 ) {
F_29 ( L_24 ) ;
return - V_15 ;
}
F_39 ( V_2 -> V_4 . V_43 , V_61 L_25 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 , V_73 ) ;
if ( V_2 -> V_4 . V_5 == V_6 || ! V_2 -> V_59 ) {
F_30 ( V_2 -> V_4 . V_43 , V_61 L_26 ,
V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
return - V_15 ;
}
F_23 ( & V_2 -> V_3 ) ;
switch ( V_73 ) {
case V_77 :
V_76 = F_58 ( V_2 -> V_4 . V_55 , ( T_2 V_78 * ) V_74 ) ;
break;
case V_79 :
if ( F_37 ( V_2 -> V_4 . V_55 ) ) {
V_76 = - V_80 ;
break;
}
V_76 = F_58 ( F_59
( V_2 -> V_4 . V_55 & V_81 ) ,
( T_2 V_78 * ) V_74 ) ;
break;
case V_82 :
if ( F_37 ( V_2 -> V_4 . V_55 ) ) {
V_76 = - V_80 ;
break;
}
V_76 = F_60 ( V_75 , ( T_2 V_78 * ) V_74 ) ;
if ( ! V_76 && ! ( F_61 ( V_75 ) & V_2 -> V_4 . V_55 ) )
V_76 = - V_44 ;
break;
case V_83 :
V_76 = F_58 ( V_2 -> V_4 . V_37 , ( T_2 V_78 * ) V_74 ) ;
break;
case V_84 :
if ( ! ( V_2 -> V_4 . V_55 & V_85 ) ||
V_2 -> V_4 . V_86 == 0 ) {
V_76 = - V_80 ;
break;
}
V_76 = F_58 ( V_2 -> V_4 . V_86 , ( T_2 V_78 * ) V_74 ) ;
break;
case V_87 :
if ( ! ( V_2 -> V_4 . V_55 & V_85 ) ||
V_2 -> V_4 . V_88 == 0 ) {
V_76 = - V_80 ;
break;
}
V_76 = F_58 ( V_2 -> V_4 . V_88 , ( T_2 V_78 * ) V_74 ) ;
break;
default:
V_76 = - V_44 ;
}
F_27 ( & V_2 -> V_3 ) ;
return V_76 ;
}
T_3 F_62 ( struct V_64 * V_64 ,
char V_78 * V_89 ,
T_4 V_90 ,
T_5 * V_91 )
{
struct V_1 * V_2 = V_51 [ F_42 ( F_54 ( V_64 ) ) ] ;
unsigned char * V_9 ;
int V_68 = 0 , V_92 = 0 ;
F_63 ( V_69 , V_93 ) ;
if ( ! V_2 ) {
F_29 ( L_22 ) ;
return - V_15 ;
}
F_39 ( V_2 -> V_4 . V_43 , V_61 L_27 , V_2 -> V_4 . V_54 , V_2 -> V_4 . V_5 ) ;
V_9 = F_31 ( V_2 -> V_34 , V_40 ) ;
if ( ! V_9 )
return - V_24 ;
if ( F_43 ( & V_2 -> V_3 ) ) {
V_68 = - V_65 ;
goto V_94;
}
if ( ! V_2 -> V_59 ) {
V_68 = - V_15 ;
goto V_95;
}
if ( V_90 % V_2 -> V_34 ) {
V_68 = - V_44 ;
goto V_95;
}
F_64 ( & V_2 -> V_9 -> V_20 , & V_69 ) ;
while ( V_92 < V_90 && V_68 == 0 ) {
if ( F_56 ( V_2 -> V_9 ) ) {
if ( V_92 )
break;
if ( V_64 -> V_96 & V_97 ) {
V_68 = - V_98 ;
break;
}
if ( F_65 ( V_93 ) ) {
V_68 = - V_65 ;
break;
}
F_27 ( & V_2 -> V_3 ) ;
F_12 ( V_19 ) ;
F_16 () ;
F_12 ( V_99 ) ;
if ( F_43 ( & V_2 -> V_3 ) ) {
V_68 = - V_65 ;
F_66 ( & V_2 -> V_9 -> V_20 , & V_69 ) ;
goto V_94;
}
if ( ! V_2 -> V_59 ) {
V_68 = - V_15 ;
goto V_95;
}
} else {
F_67 ( V_2 -> V_9 , V_9 ) ;
V_68 = F_68 ( ( void V_78 * ) V_89 + V_92 , V_9 ,
V_2 -> V_9 -> V_34 ) ;
if ( ! V_68 )
V_92 += V_2 -> V_9 -> V_34 ;
else
V_68 = - V_100 ;
}
}
F_66 ( & V_2 -> V_9 -> V_20 , & V_69 ) ;
V_95:
F_27 ( & V_2 -> V_3 ) ;
V_94:
F_8 ( V_9 ) ;
return V_68 ? V_68 : V_92 ;
}
void * F_69 ( struct V_64 * V_64 )
{
return V_51 [ F_42 ( F_54 ( V_64 ) ) ] -> V_4 . V_14 ;
}
T_3 F_70 ( struct V_64 * V_64 , const char V_78 * V_89 ,
T_4 V_90 , T_5 * V_91 )
{
struct V_1 * V_2 = V_51 [ F_42 ( F_54 ( V_64 ) ) ] ;
if ( ! V_2 ) {
F_29 ( L_22 ) ;
return - V_15 ;
}
if ( ! V_2 -> V_59 )
return - V_15 ;
return - V_44 ;
}
static int T_6 F_71 ( void )
{
int V_23 ;
V_7 = F_72 ( V_29 , L_28 ) ;
if ( F_34 ( V_7 ) ) {
F_29 ( L_29 ) ;
return F_73 ( V_7 ) ;
}
V_23 = F_74 ( & V_8 , 0 , V_45 ,
V_101 ) ;
if ( V_23 ) {
F_75 ( V_7 ) ;
F_29 ( L_30 ) ;
return V_23 ;
}
F_76 ( L_31 ,
F_6 ( V_8 ) ) ;
return 0 ;
}
static void T_7 F_77 ( void )
{
F_75 ( V_7 ) ;
F_78 ( V_8 , V_45 ) ;
F_76 ( L_32 ) ;
}
