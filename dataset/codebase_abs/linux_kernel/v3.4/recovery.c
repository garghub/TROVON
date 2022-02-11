static int F_1 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( * V_3 ++ != 0xff )
return 0 ;
return 1 ;
}
static int F_2 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( * V_3 ++ != 0xff )
return V_4 ;
return - 1 ;
}
static int F_3 ( const struct V_5 * V_6 , int V_7 , void * * V_8 ,
struct V_9 * * V_10 , void * * V_11 )
{
const int V_12 = V_6 -> V_13 ;
int V_14 , V_15 , V_2 ;
void * V_16 , * V_1 ;
V_16 = F_4 ( V_6 -> V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_14 = F_5 ( V_6 , V_7 , V_16 , 0 , V_6 -> V_17 , 0 ) ;
if ( V_14 && V_14 != - V_19 )
goto V_20;
V_15 = 0 ;
V_1 = V_16 ;
V_2 = V_6 -> V_17 ;
while ( V_15 + V_21 <= V_6 -> V_17 ) {
struct V_22 * V_23 = V_1 ;
if ( F_6 ( V_23 -> V_24 ) != V_25 )
break;
V_15 += V_12 ;
V_1 += V_12 ;
V_2 -= V_12 ;
}
if ( V_15 ) {
int V_26 ;
V_15 -= V_12 ;
V_1 -= V_12 ;
V_2 += V_12 ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_26 != V_27 && V_15 ) {
V_15 -= V_12 ;
V_1 -= V_12 ;
V_2 += V_12 ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_26 != V_27 )
goto V_28;
}
if ( V_26 == V_27 ) {
struct V_22 * V_23 = V_1 ;
if ( V_23 -> V_29 != V_30 )
goto V_28;
F_8 ( L_1 , V_7 , V_15 ) ;
* V_10 = V_1 ;
V_15 += V_12 ;
V_1 += V_12 ;
V_2 -= V_12 ;
}
}
if ( V_15 < V_6 -> V_17 ) {
if ( ! F_1 ( V_1 , F_9 ( int , V_2 , V_12 ) ) ) {
* V_11 = V_1 ;
F_8 ( L_2 , V_7 , V_15 ) ;
}
V_15 += V_12 ;
V_1 += V_12 ;
V_2 -= V_12 ;
}
if ( V_15 < V_6 -> V_17 )
if ( ! F_1 ( V_1 , V_2 ) )
goto V_28;
* V_8 = V_16 ;
return 0 ;
V_28:
V_14 = - V_31 ;
V_20:
F_10 ( V_16 ) ;
* V_10 = NULL ;
* V_11 = NULL ;
return V_14 ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_14 = 0 , V_7 = V_32 , V_12 = V_6 -> V_13 ;
T_2 V_33 ;
F_8 ( L_3 ) ;
V_33 = V_10 -> V_34 ;
V_10 -> V_34 |= F_12 ( V_35 ) ;
F_13 ( V_6 , V_10 , V_21 , 1 ) ;
V_14 = F_14 ( V_6 , V_7 , V_10 , V_12 , V_36 ) ;
if ( V_14 )
goto V_37;
V_14 = F_14 ( V_6 , V_7 + 1 , V_10 , V_12 , V_36 ) ;
if ( V_14 )
goto V_37;
V_37:
V_10 -> V_34 = V_33 ;
return V_14 ;
}
int F_15 ( struct V_5 * V_6 )
{
void * V_38 = NULL , * V_39 = NULL , * V_40 = NULL , * V_41 = NULL ;
struct V_9 * V_42 = NULL , * V_43 = NULL , * V_10 ;
const int V_12 = V_6 -> V_13 ;
int V_14 , V_44 , V_45 ;
F_8 ( L_3 ) ;
V_14 = F_3 ( V_6 , V_32 , & V_38 , & V_42 , & V_40 ) ;
if ( V_14 )
goto V_20;
V_14 = F_3 ( V_6 , V_32 + 1 , & V_39 , & V_43 , & V_41 ) ;
if ( V_14 )
goto V_20;
if ( V_42 ) {
V_44 = ( void * ) V_42 - V_38 ;
if ( ( F_6 ( V_42 -> V_34 ) & V_35 ) &&
( V_44 == 0 && ! V_40 ) ) {
F_8 ( L_4 ) ;
V_10 = V_42 ;
} else if ( V_43 ) {
V_45 = ( void * ) V_43 - V_39 ;
if ( V_44 == V_45 ) {
if ( memcmp ( ( void * ) V_42 + V_46 ,
( void * ) V_43 + V_46 ,
V_21 - V_46 ) )
goto V_28;
V_10 = V_42 ;
} else if ( V_45 + V_12 == V_44 ) {
if ( V_40 )
goto V_28;
V_10 = V_42 ;
} else if ( V_44 == 0 &&
V_6 -> V_17 - V_45 - V_12 < V_12 ) {
if ( V_40 )
goto V_28;
V_10 = V_42 ;
} else
goto V_28;
} else {
if ( V_44 != 0 || V_40 )
goto V_28;
V_10 = V_42 ;
}
} else {
if ( ! V_43 )
goto V_28;
V_45 = ( void * ) V_43 - V_39 ;
if ( V_45 + V_12 + V_12 <= V_6 -> V_17 )
goto V_28;
V_10 = V_43 ;
}
F_16 ( L_5 ,
( V_10 == V_42 ? V_32 : V_32 + 1 ) ) ;
memcpy ( V_6 -> V_47 , V_10 , V_21 ) ;
if ( V_6 -> V_48 ) {
V_6 -> V_49 = F_17 ( V_12 , V_50 ) ;
if ( ! V_6 -> V_49 ) {
V_14 = - V_18 ;
goto V_20;
}
memcpy ( V_6 -> V_49 , V_6 -> V_47 , V_21 ) ;
V_6 -> V_47 -> V_34 |= F_12 ( V_51 ) ;
} else {
V_6 -> V_52 = F_18 ( V_10 -> V_23 . V_53 ) - 1 ;
V_14 = F_11 ( V_6 , V_6 -> V_47 ) ;
if ( V_14 )
goto V_20;
}
F_10 ( V_39 ) ;
F_10 ( V_38 ) ;
return 0 ;
V_28:
V_14 = - V_31 ;
V_20:
F_19 ( L_6 ) ;
if ( V_42 ) {
F_20 ( L_7 ) ;
F_21 ( V_6 , V_42 ) ;
}
if ( V_43 ) {
F_20 ( L_8 ) ;
F_21 ( V_6 , V_43 ) ;
}
F_10 ( V_39 ) ;
F_10 ( V_38 ) ;
return V_14 ;
}
int F_22 ( struct V_5 * V_6 )
{
int V_14 ;
if ( ! V_6 -> V_49 )
return 0 ;
V_6 -> V_49 -> V_34 |= F_12 ( V_51 ) ;
V_6 -> V_47 -> V_34 |= F_12 ( V_51 ) ;
V_14 = F_11 ( V_6 , V_6 -> V_49 ) ;
if ( V_14 )
return V_14 ;
F_23 ( V_6 -> V_49 ) ;
V_6 -> V_49 = NULL ;
return 0 ;
}
static int F_24 ( const struct V_5 * V_6 , void * V_1 , int V_15 )
{
int V_54 , V_55 ;
T_1 * V_3 ;
V_54 = F_25 ( V_15 + 1 , V_6 -> V_56 ) ;
V_55 = V_6 -> V_17 - V_54 ;
V_3 = V_1 + V_54 - V_15 ;
return F_1 ( V_3 , V_55 ) ;
}
static void F_26 ( const struct V_5 * V_6 , void * * V_1 , int V_7 ,
int * V_15 , int * V_2 )
{
int V_54 , V_57 ;
V_7 = V_7 ;
F_8 ( L_9 , V_7 , * V_15 ) ;
F_27 ( ! ( * V_15 & 7 ) ) ;
V_54 = F_25 ( * V_15 , V_6 -> V_58 ) ;
V_57 = V_54 - * V_15 ;
F_28 ( V_6 , * V_1 , V_57 ) ;
* V_15 += V_57 ;
* V_1 += V_57 ;
* V_2 -= V_57 ;
memset ( * V_1 , 0xff , V_6 -> V_17 - V_54 ) ;
}
static int F_29 ( const struct V_5 * V_6 , void * V_1 , int V_2 ,
int V_7 , int V_15 )
{
struct V_22 * V_23 = V_1 ;
int V_59 , V_60 = F_6 ( V_23 -> V_2 ) ;
V_59 = F_25 ( V_15 + V_46 , V_6 -> V_56 ) - V_15 ;
if ( F_1 ( V_1 + V_59 , V_2 - V_59 ) )
return 1 ;
if ( F_30 ( V_6 , V_1 , V_7 , V_15 , 1 , 0 ) != - V_61 ) {
F_8 ( L_10 , V_7 , V_15 ) ;
return 0 ;
}
V_59 = F_25 ( V_15 + V_60 , V_6 -> V_56 ) - V_15 ;
if ( F_1 ( V_1 + V_59 , V_2 - V_59 ) )
return 1 ;
F_8 ( L_11 , V_7 , V_15 + V_59 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_62 * V_63 ,
int V_64 )
{
int V_7 = V_63 -> V_7 , V_65 = V_64 ;
if ( ! F_32 ( & V_63 -> V_66 ) ) {
struct V_67 * V_68 ;
V_68 = F_33 ( V_63 -> V_66 . V_69 ,
struct V_67 , V_70 ) ;
V_65 = V_68 -> V_15 + V_68 -> V_2 ;
}
if ( V_6 -> V_48 && ! V_6 -> V_71 ) {
struct V_72 * V_73 ;
F_8 ( L_12 ,
V_7 , V_64 , V_63 -> V_65 ) ;
V_73 = F_34 ( sizeof( struct V_72 ) , V_74 ) ;
if ( ! V_73 )
return - V_18 ;
V_73 -> V_7 = V_7 ;
V_73 -> V_65 = V_65 ;
F_35 ( & V_73 -> V_70 , & V_6 -> V_75 ) ;
} else {
int V_14 ;
F_8 ( L_13 ,
V_7 , V_64 , V_63 -> V_65 ) ;
if ( V_65 == 0 ) {
V_14 = F_36 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
} else {
int V_2 = F_25 ( V_65 , V_6 -> V_58 ) ;
if ( V_64 ) {
V_14 = F_5 ( V_6 , V_7 , V_63 -> V_1 , 0 ,
V_64 , 1 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 > V_65 ) {
int V_57 = V_2 - F_25 ( V_65 , 8 ) ;
if ( V_57 > 0 ) {
void * V_1 = V_63 -> V_1 + V_2 - V_57 ;
F_28 ( V_6 , V_1 , V_57 ) ;
}
}
V_14 = F_14 ( V_6 , V_7 , V_63 -> V_1 , V_2 ,
V_76 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static void F_37 ( struct V_62 * V_63 , int * V_15 )
{
while ( ! F_32 ( & V_63 -> V_66 ) ) {
struct V_67 * V_68 ;
struct V_22 * V_23 ;
V_68 = F_33 ( V_63 -> V_66 . V_69 , struct V_67 ,
V_70 ) ;
V_23 = V_68 -> V_77 ;
if ( V_23 -> V_78 != V_79 )
break;
F_8 ( L_14 ,
V_63 -> V_7 , V_68 -> V_15 ) ;
* V_15 = V_68 -> V_15 ;
F_38 ( & V_68 -> V_70 ) ;
F_23 ( V_68 ) ;
V_63 -> V_80 -= 1 ;
}
}
static void F_39 ( struct V_62 * V_63 , int * V_15 )
{
struct V_67 * V_68 ;
if ( ! F_32 ( & V_63 -> V_66 ) ) {
V_68 = F_33 ( V_63 -> V_66 . V_69 , struct V_67 ,
V_70 ) ;
F_8 ( L_15 , V_63 -> V_7 , V_68 -> V_15 ) ;
* V_15 = V_68 -> V_15 ;
F_38 ( & V_68 -> V_70 ) ;
F_23 ( V_68 ) ;
V_63 -> V_80 -= 1 ;
}
}
struct V_62 * F_40 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 , int V_81 )
{
int V_26 = 0 , V_14 , V_2 = V_6 -> V_17 - V_15 , V_64 = V_15 , V_82 ;
int V_83 = V_81 == - 1 ? 0 : V_6 -> V_84 [ V_81 ] . V_83 ;
struct V_62 * V_63 ;
void * V_1 = V_16 + V_15 ;
F_8 ( L_16 , V_7 , V_15 , V_81 , V_83 ) ;
V_63 = F_41 ( V_6 , V_7 , V_15 , V_16 ) ;
if ( F_42 ( V_63 ) )
return V_63 ;
F_27 ( V_2 >= 8 ) ;
while ( V_2 >= 8 ) {
F_43 ( L_17 ,
V_7 , V_15 , V_2 ) ;
F_44 () ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_26 == V_27 ) {
struct V_22 * V_23 = V_1 ;
int V_85 ;
V_14 = F_45 ( V_6 , V_63 , V_1 , V_15 ) ;
if ( V_14 )
goto error;
V_85 = F_25 ( F_6 ( V_23 -> V_2 ) , 8 ) ;
V_15 += V_85 ;
V_1 += V_85 ;
V_2 -= V_85 ;
} else if ( V_26 > 0 ) {
V_15 += V_26 ;
V_1 += V_26 ;
V_2 -= V_26 ;
} else if ( V_26 == V_86 ||
V_26 == V_87 ||
V_26 == V_88 ||
V_26 == V_89 ) {
F_8 ( L_18 ,
V_26 , V_7 , V_15 ) ;
break;
} else {
F_20 ( L_19 , V_26 ) ;
V_14 = - V_31 ;
goto error;
}
}
if ( V_26 == V_87 || V_26 == V_88 ) {
if ( ! F_24 ( V_6 , V_1 , V_15 ) )
goto V_90;
} else if ( V_26 == V_89 ) {
if ( ! F_29 ( V_6 , V_1 , V_2 , V_7 , V_15 ) )
goto V_90;
} else if ( ! F_1 ( V_1 , V_2 ) ) {
if ( ! F_24 ( V_6 , V_1 , V_15 ) ) {
int V_91 = F_2 ( V_1 , V_2 ) ;
F_19 ( L_20
L_21 , V_7 , V_15 , V_91 ) ;
V_15 += V_91 ;
V_1 += V_91 ;
goto V_92;
}
}
V_82 = F_46 ( V_15 , V_6 -> V_58 ) ;
if ( V_83 )
F_37 ( V_63 , & V_15 ) ;
if ( V_81 == V_93 ) {
while ( V_15 > V_82 )
F_39 ( V_63 , & V_15 ) ;
}
V_1 = V_16 + V_15 ;
V_2 = V_6 -> V_17 - V_15 ;
F_26 ( V_6 , & V_1 , V_7 , & V_15 , & V_2 ) ;
F_47 ( V_6 , V_63 , V_7 , V_15 ) ;
V_14 = F_31 ( V_6 , V_63 , V_64 ) ;
if ( V_14 )
goto error;
return V_63 ;
V_90:
F_20 ( L_22 , V_26 ) ;
F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
V_92:
F_48 ( V_6 , V_7 , V_15 , V_1 ) ;
V_14 = - V_61 ;
error:
F_19 ( L_23 , V_7 ) ;
F_49 ( V_63 ) ;
return F_50 ( V_14 ) ;
}
static int F_51 ( struct V_5 * V_6 , int V_7 , int V_15 ,
unsigned long long * V_94 )
{
struct V_95 * V_96 = NULL ;
int V_14 , V_26 ;
F_8 ( L_24 , V_7 , V_15 ) ;
V_96 = F_17 ( V_97 , V_50 ) ;
if ( ! V_96 )
return - V_18 ;
if ( V_6 -> V_17 - V_15 < V_97 )
goto V_28;
V_14 = F_5 ( V_6 , V_7 , ( void * ) V_96 , V_15 ,
V_97 , 0 ) ;
if ( V_14 && V_14 != - V_19 )
goto V_20;
V_26 = F_7 ( V_6 , V_96 , V_97 , V_7 , V_15 , 0 ) ;
if ( V_26 != V_27 ) {
F_20 ( L_25 ) ;
goto V_28;
}
if ( V_96 -> V_23 . V_29 != V_98 ) {
F_20 ( L_26 , V_96 -> V_23 . V_29 ) ;
goto V_28;
}
if ( F_18 ( V_96 -> V_99 ) != V_6 -> V_99 ) {
F_20 ( L_27 ,
( unsigned long long ) F_18 ( V_96 -> V_99 ) ,
V_6 -> V_99 ) ;
goto V_28;
}
* V_94 = F_18 ( V_96 -> V_23 . V_53 ) ;
F_8 ( L_28 , * V_94 ) ;
F_23 ( V_96 ) ;
return 0 ;
V_28:
V_14 = - V_31 ;
V_20:
F_19 ( L_29 ) ;
F_23 ( V_96 ) ;
return V_14 ;
}
struct V_62 * F_52 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 )
{
struct V_62 * V_63 ;
int V_100 ;
F_8 ( L_30 , V_7 ) ;
V_100 = V_7 + 1 ;
if ( V_100 >= V_101 + V_6 -> V_102 )
V_100 = V_101 ;
if ( V_100 != V_6 -> V_103 ) {
V_63 = F_53 ( V_6 , V_100 , 0 , V_16 , 0 ) ;
if ( F_42 ( V_63 ) )
return V_63 ;
if ( V_63 -> V_80 ) {
struct V_67 * V_68 ;
unsigned long long V_94 = V_6 -> V_94 ;
V_68 = F_33 ( V_63 -> V_66 . V_104 ,
struct V_67 , V_70 ) ;
if ( V_94 == 0 ) {
int V_14 ;
V_14 = F_51 ( V_6 , V_7 , V_15 , & V_94 ) ;
if ( V_14 ) {
F_49 ( V_63 ) ;
return F_50 ( V_14 ) ;
}
}
if ( V_68 -> V_53 > V_94 ) {
F_19 ( L_31
L_32 , V_7 ) ;
F_49 ( V_63 ) ;
return F_50 ( - V_61 ) ;
}
}
F_49 ( V_63 ) ;
}
return F_40 ( V_6 , V_7 , V_15 , V_16 , - 1 ) ;
}
static int F_54 ( struct V_5 * V_6 , int V_7 , int V_15 , void * V_16 )
{
int V_2 = V_6 -> V_56 , V_14 ;
if ( V_15 + V_2 > V_6 -> V_17 )
V_2 = V_6 -> V_17 - V_15 ;
if ( ! V_2 )
return 0 ;
V_14 = F_5 ( V_6 , V_7 , V_16 , V_15 , V_2 , 1 ) ;
if ( V_14 || ! F_1 ( V_16 , V_2 ) ) {
F_8 ( L_33 , V_7 , V_15 ) ;
if ( V_15 == 0 )
return F_36 ( V_6 , V_7 ) ;
V_14 = F_5 ( V_6 , V_7 , V_16 , 0 , V_15 , 1 ) ;
if ( V_14 )
return V_14 ;
return F_14 ( V_6 , V_7 , V_16 , V_15 , V_76 ) ;
}
return 0 ;
}
int F_55 ( struct V_5 * V_6 , void * V_16 )
{
int V_14 ;
F_27 ( ! V_6 -> V_48 || V_6 -> V_71 ) ;
F_8 ( L_34 , V_6 -> V_105 , V_6 -> V_106 ) ;
V_14 = F_54 ( V_6 , V_6 -> V_105 , V_6 -> V_106 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_35 , V_6 -> V_107 , V_6 -> V_108 ) ;
V_14 = F_54 ( V_6 , V_6 -> V_107 , V_6 -> V_108 , V_16 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_72 * V_73 , void * V_16 )
{
int V_14 , V_7 = V_73 -> V_7 , V_15 = 0 , V_2 = V_73 -> V_65 , V_109 = 1 ;
void * V_1 = V_16 ;
F_8 ( L_36 , V_7 , V_2 ) ;
if ( V_2 == 0 ) {
V_14 = F_36 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
V_14 = F_5 ( V_6 , V_7 , V_1 , V_15 , V_2 , 0 ) ;
if ( V_14 && V_14 != - V_19 )
return V_14 ;
while ( V_2 >= 8 ) {
int V_26 ;
F_44 () ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , V_109 ) ;
if ( V_26 == V_27 ) {
struct V_22 * V_23 = V_1 ;
int V_85 ;
V_85 = F_25 ( F_6 ( V_23 -> V_2 ) , 8 ) ;
V_15 += V_85 ;
V_1 += V_85 ;
V_2 -= V_85 ;
continue;
}
if ( V_26 > 0 ) {
V_15 += V_26 ;
V_1 += V_26 ;
V_2 -= V_26 ;
continue;
}
if ( V_26 == V_86 ) {
F_19 ( L_37 ,
V_7 , V_15 ) ;
return - V_61 ;
}
if ( V_109 ) {
V_109 = 0 ;
continue;
}
F_48 ( V_6 , V_7 , V_15 , V_1 ) ;
return - V_61 ;
}
V_2 = F_25 ( V_73 -> V_65 , V_6 -> V_58 ) ;
if ( V_2 > V_73 -> V_65 ) {
int V_57 = V_2 - F_25 ( V_73 -> V_65 , 8 ) ;
if ( V_57 > 0 ) {
V_1 = V_6 -> V_16 + V_2 - V_57 ;
F_28 ( V_6 , V_1 , V_57 ) ;
}
}
V_14 = F_14 ( V_6 , V_7 , V_16 , V_2 , V_76 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_38 , V_7 ) ;
return 0 ;
}
int F_57 ( struct V_5 * V_6 , void * V_16 )
{
F_8 ( L_3 ) ;
while ( ! F_32 ( & V_6 -> V_75 ) ) {
struct V_72 * V_73 ;
int V_14 ;
V_73 = F_33 ( V_6 -> V_75 . V_104 ,
struct V_72 , V_70 ) ;
V_14 = F_56 ( V_6 , V_73 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_38 ( & V_73 -> V_70 ) ;
F_23 ( V_73 ) ;
}
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
int V_7 , V_14 ;
V_7 = F_59 ( V_6 ) ;
if ( V_7 < 0 ) {
F_20 ( L_39 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 , & V_6 -> V_110 ) ;
return V_7 ;
}
V_14 = F_62 ( V_6 , V_7 , V_111 , V_111 , 0 ,
V_112 , 0 ) ;
if ( V_14 )
return V_14 ;
V_6 -> V_113 = V_7 ;
F_8 ( L_40 , V_7 ) ;
return F_63 ( V_6 ) ;
}
int F_64 ( struct V_5 * V_6 )
{
struct V_114 * V_115 = & V_6 -> V_84 [ V_93 ] . V_115 ;
struct V_116 V_117 ;
int V_14 ;
F_8 ( L_41 , V_115 -> V_7 , V_115 -> V_15 ) ;
V_6 -> V_113 = - 1 ;
if ( V_115 -> V_7 == - 1 || V_115 -> V_15 == V_6 -> V_17 )
return F_58 ( V_6 ) ;
V_14 = F_65 ( V_6 , & V_117 , V_115 -> V_15 , 2 ) ;
if ( V_14 ) {
if ( V_14 != - V_118 )
return V_14 ;
F_8 ( L_42 ) ;
return F_58 ( V_6 ) ;
}
F_27 ( ! ( V_117 . V_34 & V_112 ) ) ;
F_27 ( V_117 . free + V_117 . V_119 >= V_115 -> V_15 ) ;
F_8 ( L_43 ) ;
V_14 = F_63 ( V_6 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_44 , V_117 . V_7 ) ;
F_66 ( & V_115 -> V_120 , V_115 -> V_81 ) ;
V_14 = F_67 ( V_6 , & V_117 ) ;
if ( V_14 >= 0 ) {
int V_121 = F_68 ( V_115 ) ;
if ( V_121 )
V_14 = V_121 ;
}
F_69 ( & V_115 -> V_120 ) ;
if ( V_14 < 0 ) {
F_20 ( L_45 , V_14 ) ;
if ( V_14 == - V_122 )
V_14 = - V_31 ;
return V_14 ;
}
F_27 ( V_14 == V_123 ) ;
if ( V_14 != V_123 )
return - V_31 ;
V_14 = F_36 ( V_6 , V_6 -> V_113 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_46 , V_117 . V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 , T_3 V_124 , T_4 V_125 ,
T_4 V_126 , int V_127 )
{
struct V_128 * * V_3 = & V_6 -> V_129 . V_128 , * V_130 = NULL ;
struct V_131 * V_132 ;
while ( * V_3 ) {
V_130 = * V_3 ;
V_132 = F_71 ( V_130 , struct V_131 , V_133 ) ;
if ( V_124 < V_132 -> V_124 )
V_3 = & ( * V_3 ) -> V_134 ;
else
V_3 = & ( * V_3 ) -> V_135 ;
}
V_132 = F_34 ( sizeof( struct V_131 ) , V_50 ) ;
if ( ! V_132 )
return - V_18 ;
V_132 -> V_124 = V_124 ;
V_132 -> V_125 = V_125 ;
V_132 -> V_126 = V_126 ;
V_132 -> V_127 = V_127 ;
F_72 ( & V_132 -> V_133 , V_130 , V_3 ) ;
F_73 ( & V_132 -> V_133 , & V_6 -> V_129 ) ;
return 0 ;
}
static struct V_131 * F_74 ( struct V_5 * V_6 , T_3 V_124 )
{
struct V_128 * V_3 = V_6 -> V_129 . V_128 ;
struct V_131 * V_132 ;
while ( V_3 ) {
V_132 = F_71 ( V_3 , struct V_131 , V_133 ) ;
if ( V_124 < V_132 -> V_124 )
V_3 = V_3 -> V_134 ;
else if ( V_124 > V_132 -> V_124 )
V_3 = V_3 -> V_135 ;
else
return V_132 ;
}
return NULL ;
}
static void F_75 ( struct V_5 * V_6 , T_3 V_124 )
{
struct V_131 * V_132 = F_74 ( V_6 , V_124 ) ;
if ( ! V_132 )
return;
F_76 ( & V_132 -> V_133 , & V_6 -> V_129 ) ;
F_23 ( V_132 ) ;
}
void F_77 ( struct V_5 * V_6 )
{
struct V_128 * V_136 = V_6 -> V_129 . V_128 ;
struct V_131 * V_132 ;
while ( V_136 ) {
if ( V_136 -> V_134 ) {
V_136 = V_136 -> V_134 ;
continue;
} else if ( V_136 -> V_135 ) {
V_136 = V_136 -> V_135 ;
continue;
}
V_132 = F_71 ( V_136 , struct V_131 , V_133 ) ;
if ( V_132 -> V_137 )
F_78 ( V_132 -> V_137 ) ;
V_136 = F_79 ( V_136 ) ;
if ( V_136 ) {
if ( V_136 -> V_134 == & V_132 -> V_133 )
V_136 -> V_134 = NULL ;
else
V_136 -> V_135 = NULL ;
}
F_23 ( V_132 ) ;
}
V_6 -> V_129 = V_138 ;
}
int F_80 ( struct V_5 * V_6 , union V_139 * V_140 ,
int V_141 , T_4 V_142 )
{
T_3 V_124 = F_81 ( V_6 , V_140 ) ;
struct V_131 * V_132 ;
int V_14 ;
switch ( F_82 ( V_6 , V_140 ) ) {
case V_143 :
if ( V_141 )
F_75 ( V_6 , V_124 ) ;
else {
V_132 = F_74 ( V_6 , V_124 ) ;
if ( V_132 ) {
V_132 -> V_125 = V_142 ;
V_132 -> V_127 = 1 ;
} else {
V_14 = F_70 ( V_6 , V_124 , V_142 , 0 , 1 ) ;
if ( V_14 )
return V_14 ;
}
}
break;
case V_144 :
V_132 = F_74 ( V_6 , V_124 ) ;
if ( V_132 ) {
if ( V_142 > V_132 -> V_126 )
V_132 -> V_126 = V_142 ;
} else {
V_14 = F_70 ( V_6 , V_124 , 0 , V_142 , 0 ) ;
if ( V_14 )
return V_14 ;
}
break;
case V_145 :
V_132 = F_74 ( V_6 , V_124 ) ;
if ( V_132 )
V_132 -> V_126 = V_142 ;
break;
}
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
struct V_146 * V_147 = V_6 -> V_16 ;
unsigned char * V_3 ;
union V_139 V_140 ;
int V_14 , V_7 , V_15 , V_2 ;
T_4 V_125 ;
T_5 V_148 ;
F_84 ( V_6 , & V_140 , V_132 -> V_124 ) ;
V_14 = F_85 ( V_6 , & V_140 , V_147 , & V_7 , & V_15 ) ;
if ( V_14 )
goto V_37;
V_125 = F_18 ( V_147 -> V_149 ) ;
if ( V_125 >= V_132 -> V_126 )
return 0 ;
V_14 = F_5 ( V_6 , V_7 , V_6 -> V_16 , 0 , V_6 -> V_17 , 1 ) ;
if ( V_14 )
goto V_37;
V_147 = V_6 -> V_16 + V_15 ;
V_147 -> V_149 = F_86 ( V_132 -> V_126 ) ;
V_2 = F_6 ( V_147 -> V_23 . V_2 ) ;
V_148 = F_87 ( V_150 , ( void * ) V_147 + 8 , V_2 - 8 ) ;
V_147 -> V_23 . V_148 = F_12 ( V_148 ) ;
V_3 = V_6 -> V_16 ;
V_2 = V_6 -> V_17 - 1 ;
while ( V_3 [ V_2 ] == 0xff )
V_2 -= 1 ;
V_2 = F_25 ( V_2 + 1 , V_6 -> V_58 ) ;
V_14 = F_14 ( V_6 , V_7 , V_6 -> V_16 , V_2 , V_76 ) ;
if ( V_14 )
goto V_37;
F_8 ( L_47 ,
( unsigned long ) V_132 -> V_124 , V_7 , V_15 , V_125 , V_132 -> V_126 ) ;
return 0 ;
V_37:
F_88 ( L_48 ,
( unsigned long ) V_132 -> V_124 , V_132 -> V_125 , V_132 -> V_126 , V_14 ) ;
return V_14 ;
}
int F_89 ( struct V_5 * V_6 )
{
struct V_128 * V_136 = F_90 ( & V_6 -> V_129 ) ;
while ( V_136 ) {
struct V_131 * V_132 ;
int V_14 ;
V_132 = F_71 ( V_136 , struct V_131 , V_133 ) ;
if ( ! V_132 -> V_127 ) {
union V_139 V_140 ;
F_84 ( V_6 , & V_140 , V_132 -> V_124 ) ;
V_14 = F_91 ( V_6 , & V_140 , V_6 -> V_16 ) ;
if ( V_14 && V_14 != - V_151 )
return V_14 ;
if ( V_14 == - V_151 ) {
F_8 ( L_49 ,
( unsigned long ) V_132 -> V_124 ) ;
V_14 = F_92 ( V_6 , V_132 -> V_124 ) ;
if ( V_14 )
return V_14 ;
} else {
struct V_146 * V_147 = V_6 -> V_16 ;
V_132 -> V_127 = 1 ;
V_132 -> V_125 = F_18 ( V_147 -> V_149 ) ;
}
}
if ( V_132 -> V_127 && V_132 -> V_125 < V_132 -> V_126 ) {
if ( V_6 -> V_48 ) {
struct V_137 * V_137 ;
struct V_152 * V_153 ;
F_27 ( ! V_132 -> V_137 ) ;
V_137 = F_93 ( V_6 -> V_154 , V_132 -> V_124 ) ;
if ( F_42 ( V_137 ) )
return F_94 ( V_137 ) ;
V_153 = V_152 ( V_137 ) ;
if ( V_137 -> V_125 < V_132 -> V_126 ) {
F_8 ( L_50 ,
( unsigned long ) V_132 -> V_124 ,
V_137 -> V_125 , V_132 -> V_126 ) ;
V_137 -> V_125 = V_132 -> V_126 ;
V_153 -> V_155 = V_132 -> V_126 ;
V_153 -> V_156 = V_132 -> V_126 ;
V_132 -> V_137 = V_137 ;
V_136 = F_95 ( V_136 ) ;
continue;
}
F_78 ( V_137 ) ;
} else {
V_14 = F_83 ( V_6 , V_132 ) ;
if ( V_14 )
return V_14 ;
if ( V_132 -> V_137 )
F_78 ( V_132 -> V_137 ) ;
}
}
V_136 = F_95 ( V_136 ) ;
F_76 ( & V_132 -> V_133 , & V_6 -> V_129 ) ;
F_23 ( V_132 ) ;
}
return 0 ;
}
