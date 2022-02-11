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
int V_21 = - V_22 ;
struct V_23 * V_4 = & V_2 -> V_4 ;
struct V_24 * V_24 ;
V_24 = F_18 ( sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
goto V_26;
if ( V_4 -> V_27 ) {
F_19 ( V_24 , V_4 -> V_27 ) ;
V_24 -> V_28 = V_4 -> V_28 ;
} else {
F_19 ( V_24 , & V_29 ) ;
V_24 -> V_28 = V_30 ;
}
V_21 = F_20 ( & V_24 -> V_31 , L_1 , V_4 -> V_5 ) ;
if ( V_21 )
goto V_26;
V_21 = F_21 ( V_24 , F_5 ( F_6 ( V_8 ) , V_4 -> V_5 ) , 1 ) ;
if ( V_21 ) {
F_22 ( & V_24 -> V_31 ) ;
goto V_26;
}
V_2 -> V_24 = V_24 ;
return 0 ;
V_26:
F_8 ( V_24 ) ;
return V_21 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
int V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
struct V_23 * V_4 = & V_2 -> V_4 ;
F_24 ( & V_36 ) ;
V_33 = F_25 ( V_4 -> V_37 ) +
( V_4 -> V_37 % 8 ? 1 : 0 ) ;
V_35 = V_4 -> V_35 ? V_4 -> V_35 : V_38 / V_33 ;
V_34 = V_4 -> V_34 ? V_4 -> V_34 : V_33 ;
if ( V_4 -> V_10 ) {
V_2 -> V_9 = V_4 -> V_10 ;
} else {
V_2 -> V_9 = F_26 ( sizeof( struct V_39 ) , V_25 ) ;
if ( ! V_2 -> V_9 ) {
V_32 = - V_22 ;
goto V_40;
}
V_32 = F_27 ( V_2 -> V_9 , V_34 , V_35 ) ;
if ( V_32 ) {
F_8 ( V_2 -> V_9 ) ;
goto V_40;
}
}
V_2 -> V_34 = V_2 -> V_9 -> V_34 ;
V_40:
F_28 ( & V_36 ) ;
return V_32 ;
}
static int F_29 ( struct V_23 * V_4 )
{
struct V_1 * V_2 ;
int V_5 ;
int V_32 ;
if ( ! V_4 ) {
F_30 ( L_2 ) ;
return - V_41 ;
}
if ( ! V_4 -> V_42 ) {
F_30 ( L_3 ) ;
return - V_43 ;
}
if ( V_4 -> V_5 >= V_44 ) {
F_31 ( V_4 -> V_42 , L_4 ,
V_44 - 1 ) ;
return - V_41 ;
}
if ( V_4 -> V_37 < 1 || V_4 -> V_37 > ( V_38 * 8 ) ) {
F_31 ( V_4 -> V_42 , L_5 ,
V_38 * 8 ) ;
return - V_41 ;
}
if ( V_4 -> V_45 ) {
if ( 2 > V_4 -> V_45 || V_46 < V_4 -> V_45 ) {
F_31 ( V_4 -> V_42 , L_6 ,
V_4 -> V_45 ) ;
return - V_41 ;
}
if ( ! V_4 -> V_13 ) {
F_31 ( V_4 -> V_42 , L_7 ) ;
return - V_41 ;
}
} else if ( ! V_4 -> V_10 && ! ( V_4 -> V_27 && V_4 -> V_27 -> V_47 &&
V_4 -> V_27 -> V_48 && V_4 -> V_27 -> V_49 ) ) {
F_31 ( V_4 -> V_42 , L_8 ) ;
return - V_41 ;
}
F_24 ( & V_36 ) ;
V_5 = V_4 -> V_5 ;
if ( V_5 < 0 ) {
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ )
if ( ! V_50 [ V_5 ] )
break;
if ( V_5 == V_44 ) {
F_31 ( V_4 -> V_42 , L_9 ) ;
V_32 = - V_22 ;
goto V_51;
}
} else if ( V_50 [ V_5 ] ) {
F_31 ( V_4 -> V_42 , L_10 , V_5 ) ;
V_32 = - V_52 ;
goto V_51;
}
V_2 = F_18 ( sizeof( struct V_1 ) , V_25 ) ;
if ( ! V_2 ) {
V_32 = - V_22 ;
goto V_51;
}
F_1 ( V_2 ) ;
V_50 [ V_5 ] = V_2 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_53 [ sizeof( V_4 -> V_53 ) - 1 ] = '\0' ;
if ( V_4 -> V_54 == 0 )
V_4 -> V_54 = V_55 ;
V_2 -> V_4 = * V_4 ;
F_32 ( V_7 , V_2 -> V_4 . V_42 ,
F_5 ( F_6 ( V_8 ) , V_2 -> V_4 . V_5 ) , NULL ,
L_11 , V_2 -> V_4 . V_5 ) ;
if ( V_4 -> V_45 ) {
V_2 -> V_18 = V_46 / V_4 -> V_45 ;
V_2 -> V_16 = F_33 ( F_11 , ( void * ) V_2 , L_12 ) ;
if ( F_34 ( V_2 -> V_16 ) ) {
F_31 ( V_4 -> V_42 , L_13 ,
V_4 -> V_5 ) ;
V_32 = - V_56 ;
goto V_57;
}
} else {
V_2 -> V_18 = 0 ;
}
V_32 = F_17 ( V_2 ) ;
if ( V_32 )
goto V_57;
V_2 -> V_58 = 1 ;
F_28 ( & V_36 ) ;
F_35 ( V_2 -> V_4 . V_42 , L_14 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
return V_5 ;
V_57:
F_4 ( V_7 , F_5 ( F_6 ( V_8 ) , V_2 -> V_4 . V_5 ) ) ;
V_51:
F_28 ( & V_36 ) ;
return V_32 ;
}
int F_36 ( struct V_23 * V_4 )
{
int V_5 , V_32 = 0 ;
V_5 = F_29 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_37 ( V_4 -> V_54 ) ) {
V_32 = F_23 ( V_50 [ V_5 ] ) ;
if ( V_32 )
F_38 ( V_5 ) ;
}
return V_32 ? V_32 : V_5 ;
}
int F_38 ( int V_5 )
{
struct V_1 * V_2 ;
struct V_24 * V_24 ;
if ( V_5 < 0 || V_5 >= V_44 ) {
F_30 ( L_15 ,
V_5 , V_44 - 1 ) ;
return - V_41 ;
}
V_2 = V_50 [ V_5 ] ;
if ( ! V_2 ) {
F_30 ( L_16 ) ;
return - V_59 ;
}
V_24 = V_2 -> V_24 ;
F_24 ( & V_36 ) ;
if ( V_2 -> V_4 . V_5 != V_5 ) {
F_31 ( V_2 -> V_4 . V_42 , L_17 ,
V_5 ) ;
F_28 ( & V_36 ) ;
return - V_59 ;
}
if ( V_2 -> V_16 )
F_10 ( V_2 -> V_16 ) ;
F_39 ( V_2 -> V_4 . V_42 , L_18 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
V_2 -> V_58 = 0 ;
if ( V_2 -> V_17 ) {
F_39 ( V_2 -> V_4 . V_42 , V_60 L_19 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
F_15 ( & V_2 -> V_9 -> V_20 ) ;
F_24 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 . V_61 )
V_2 -> V_4 . V_61 ( V_2 -> V_4 . V_14 ) ;
F_40 ( V_24 -> V_28 ) ;
F_28 ( & V_2 -> V_3 ) ;
} else {
F_3 ( V_2 ) ;
F_41 ( V_24 ) ;
F_8 ( V_24 ) ;
F_8 ( V_2 ) ;
V_50 [ V_5 ] = NULL ;
}
F_28 ( & V_36 ) ;
return 0 ;
}
int F_42 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
struct V_1 * V_2 ;
struct V_24 * V_24 ;
int V_21 = 0 ;
if ( F_43 ( V_62 ) >= V_44 ) {
F_30 ( L_20 , F_43 ( V_62 ) ) ;
return - V_15 ;
}
if ( F_44 ( & V_36 ) )
return - V_64 ;
V_2 = V_50 [ F_43 ( V_62 ) ] ;
if ( ! V_2 ) {
V_21 = - V_15 ;
goto error;
}
F_39 ( V_2 -> V_4 . V_42 , V_60 L_21 , V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
if ( V_2 -> V_4 . V_5 == V_6 ) {
V_21 = - V_15 ;
goto error;
}
if ( V_2 -> V_17 ) {
V_21 = - V_52 ;
goto error;
}
if ( V_2 -> V_4 . V_65 ) {
V_21 = F_45 ( V_2 -> V_4 . V_65 ) ;
if ( V_21 )
goto error;
}
V_24 = V_2 -> V_24 ;
if ( F_46 ( V_24 -> V_28 ) ) {
V_2 -> V_17 ++ ;
if ( V_2 -> V_4 . V_66 )
V_21 = V_2 -> V_4 . V_66 ( V_2 -> V_4 . V_14 ) ;
if ( V_21 ) {
F_40 ( V_24 -> V_28 ) ;
V_2 -> V_17 -- ;
} else {
F_47 ( V_2 -> V_9 ) ;
}
if ( V_2 -> V_16 )
F_48 ( V_2 -> V_16 ) ;
}
error:
F_28 ( & V_36 ) ;
F_49 ( V_62 , V_63 ) ;
return V_21 ;
}
int F_50 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
struct V_1 * V_2 = V_50 [ F_43 ( V_62 ) ] ;
struct V_24 * V_24 ;
int V_67 ;
if ( ! V_2 ) {
F_30 ( L_22 ) ;
return - V_43 ;
}
V_24 = V_2 -> V_24 ;
V_67 = F_51 ( & V_36 ) ;
F_52 ( V_67 ) ;
F_53 ( V_2 -> V_4 . V_65 ) ;
V_2 -> V_17 -- ;
if ( V_2 -> V_58 ) {
if ( V_2 -> V_4 . V_61 )
V_2 -> V_4 . V_61 ( V_2 -> V_4 . V_14 ) ;
F_40 ( V_24 -> V_28 ) ;
} else {
F_3 ( V_2 ) ;
F_41 ( V_24 ) ;
V_50 [ V_2 -> V_4 . V_5 ] = NULL ;
F_8 ( V_24 ) ;
F_8 ( V_2 ) ;
}
if ( ! V_67 )
F_28 ( & V_36 ) ;
return 0 ;
}
unsigned int F_54 ( struct V_63 * V_63 , T_1 * V_68 )
{
struct V_1 * V_2 = V_50 [ F_43 ( F_55 ( V_63 ) ) ] ;
unsigned int V_67 ;
if ( ! V_2 ) {
F_30 ( L_22 ) ;
return V_69 ;
}
if ( ! V_2 -> V_58 )
return V_69 ;
if ( V_2 -> V_9 ) {
F_56 ( V_63 , & V_2 -> V_9 -> V_20 , V_68 ) ;
if ( F_57 ( V_2 -> V_9 ) )
V_67 = 0 ;
else
V_67 = V_70 | V_71 ;
} else
V_67 = V_69 ;
F_39 ( V_2 -> V_4 . V_42 , V_60 L_23 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 , V_67 ) ;
return V_67 ;
}
long F_58 ( struct V_63 * V_63 , unsigned int V_72 , unsigned long V_73 )
{
T_2 V_74 ;
int V_75 = 0 ;
struct V_1 * V_2 = V_50 [ F_43 ( F_55 ( V_63 ) ) ] ;
if ( ! V_2 ) {
F_30 ( L_24 ) ;
return - V_15 ;
}
F_39 ( V_2 -> V_4 . V_42 , V_60 L_25 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 , V_72 ) ;
if ( V_2 -> V_4 . V_5 == V_6 || ! V_2 -> V_58 ) {
F_31 ( V_2 -> V_4 . V_42 , V_60 L_26 ,
V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
return - V_15 ;
}
F_24 ( & V_2 -> V_3 ) ;
switch ( V_72 ) {
case V_76 :
V_75 = F_59 ( V_2 -> V_4 . V_54 , ( T_2 V_77 * ) V_73 ) ;
break;
case V_78 :
if ( F_37 ( V_2 -> V_4 . V_54 ) ) {
V_75 = - V_79 ;
break;
}
V_75 = F_59 ( F_60
( V_2 -> V_4 . V_54 & V_80 ) ,
( T_2 V_77 * ) V_73 ) ;
break;
case V_81 :
if ( F_37 ( V_2 -> V_4 . V_54 ) ) {
V_75 = - V_79 ;
break;
}
V_75 = F_61 ( V_74 , ( T_2 V_77 * ) V_73 ) ;
if ( ! V_75 && ! ( F_62 ( V_74 ) & V_2 -> V_4 . V_54 ) )
V_75 = - V_43 ;
break;
case V_82 :
V_75 = F_59 ( V_2 -> V_4 . V_37 , ( T_2 V_77 * ) V_73 ) ;
break;
case V_83 :
if ( ! ( V_2 -> V_4 . V_54 & V_84 ) ||
V_2 -> V_4 . V_85 == 0 ) {
V_75 = - V_79 ;
break;
}
V_75 = F_59 ( V_2 -> V_4 . V_85 , ( T_2 V_77 * ) V_73 ) ;
break;
case V_86 :
if ( ! ( V_2 -> V_4 . V_54 & V_84 ) ||
V_2 -> V_4 . V_87 == 0 ) {
V_75 = - V_79 ;
break;
}
V_75 = F_59 ( V_2 -> V_4 . V_87 , ( T_2 V_77 * ) V_73 ) ;
break;
default:
V_75 = - V_43 ;
}
F_28 ( & V_2 -> V_3 ) ;
return V_75 ;
}
T_3 F_63 ( struct V_63 * V_63 ,
char V_77 * V_88 ,
T_4 V_89 ,
T_5 * V_90 )
{
struct V_1 * V_2 = V_50 [ F_43 ( F_55 ( V_63 ) ) ] ;
unsigned char * V_9 ;
int V_67 = 0 , V_91 = 0 ;
F_64 ( V_68 , V_92 ) ;
if ( ! V_2 ) {
F_30 ( L_22 ) ;
return - V_15 ;
}
F_39 ( V_2 -> V_4 . V_42 , V_60 L_27 , V_2 -> V_4 . V_53 , V_2 -> V_4 . V_5 ) ;
V_9 = F_18 ( V_2 -> V_34 , V_25 ) ;
if ( ! V_9 )
return - V_22 ;
if ( F_44 ( & V_2 -> V_3 ) ) {
V_67 = - V_64 ;
goto V_93;
}
if ( ! V_2 -> V_58 ) {
V_67 = - V_15 ;
goto V_94;
}
if ( V_89 % V_2 -> V_34 ) {
V_67 = - V_43 ;
goto V_94;
}
F_65 ( & V_2 -> V_9 -> V_20 , & V_68 ) ;
F_12 ( V_19 ) ;
while ( V_91 < V_89 && V_67 == 0 ) {
if ( F_57 ( V_2 -> V_9 ) ) {
if ( V_91 )
break;
if ( V_63 -> V_95 & V_96 ) {
V_67 = - V_97 ;
break;
}
if ( F_66 ( V_92 ) ) {
V_67 = - V_64 ;
break;
}
F_28 ( & V_2 -> V_3 ) ;
F_16 () ;
F_12 ( V_19 ) ;
if ( F_44 ( & V_2 -> V_3 ) ) {
V_67 = - V_64 ;
F_67 ( & V_2 -> V_9 -> V_20 , & V_68 ) ;
F_12 ( V_98 ) ;
goto V_93;
}
if ( ! V_2 -> V_58 ) {
V_67 = - V_15 ;
break;
}
} else {
F_68 ( V_2 -> V_9 , V_9 ) ;
V_67 = F_69 ( ( void V_77 * ) V_88 + V_91 , V_9 ,
V_2 -> V_9 -> V_34 ) ;
if ( ! V_67 )
V_91 += V_2 -> V_9 -> V_34 ;
else
V_67 = - V_99 ;
}
}
F_67 ( & V_2 -> V_9 -> V_20 , & V_68 ) ;
F_12 ( V_98 ) ;
V_94:
F_28 ( & V_2 -> V_3 ) ;
V_93:
F_8 ( V_9 ) ;
return V_67 ? V_67 : V_91 ;
}
void * F_70 ( struct V_63 * V_63 )
{
return V_50 [ F_43 ( F_55 ( V_63 ) ) ] -> V_4 . V_14 ;
}
T_3 F_71 ( struct V_63 * V_63 , const char V_77 * V_88 ,
T_4 V_89 , T_5 * V_90 )
{
struct V_1 * V_2 = V_50 [ F_43 ( F_55 ( V_63 ) ) ] ;
if ( ! V_2 ) {
F_30 ( L_22 ) ;
return - V_15 ;
}
if ( ! V_2 -> V_58 )
return - V_15 ;
return - V_43 ;
}
static int T_6 F_72 ( void )
{
int V_21 ;
V_7 = F_73 ( V_30 , L_28 ) ;
if ( F_34 ( V_7 ) ) {
F_30 ( L_29 ) ;
return F_74 ( V_7 ) ;
}
V_21 = F_75 ( & V_8 , 0 , V_44 ,
V_100 ) ;
if ( V_21 ) {
F_76 ( V_7 ) ;
F_30 ( L_30 ) ;
return V_21 ;
}
F_77 ( L_31 ,
F_6 ( V_8 ) ) ;
return 0 ;
}
static void T_7 F_78 ( void )
{
F_76 ( V_7 ) ;
F_79 ( V_8 , V_44 ) ;
F_77 ( L_32 ) ;
}
