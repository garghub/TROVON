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
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_16 , 0 , V_6 -> V_17 ) ;
if ( V_14 && V_14 != - V_20 )
goto V_21;
V_15 = 0 ;
V_1 = V_16 ;
V_2 = V_6 -> V_17 ;
while ( V_15 + V_22 <= V_6 -> V_17 ) {
struct V_23 * V_24 = V_1 ;
if ( F_6 ( V_24 -> V_25 ) != V_26 )
break;
V_15 += V_12 ;
V_1 += V_12 ;
V_2 -= V_12 ;
}
if ( V_15 ) {
int V_27 ;
V_15 -= V_12 ;
V_1 -= V_12 ;
V_2 += V_12 ;
V_27 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_27 != V_28 && V_15 ) {
V_15 -= V_12 ;
V_1 -= V_12 ;
V_2 += V_12 ;
V_27 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_27 != V_28 )
goto V_29;
}
if ( V_27 == V_28 ) {
struct V_23 * V_24 = V_1 ;
if ( V_24 -> V_30 != V_31 )
goto V_29;
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
goto V_29;
* V_8 = V_16 ;
return 0 ;
V_29:
V_14 = - V_32 ;
V_21:
F_10 ( V_16 ) ;
* V_10 = NULL ;
* V_11 = NULL ;
return V_14 ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_14 = 0 , V_7 = V_33 , V_12 = V_6 -> V_13 ;
T_2 V_34 ;
F_8 ( L_3 ) ;
V_34 = V_10 -> V_35 ;
V_10 -> V_35 |= F_12 ( V_36 ) ;
F_13 ( V_6 , V_10 , V_22 , 1 ) ;
V_14 = F_14 ( V_6 -> V_19 , V_7 , V_10 , V_12 , V_37 ) ;
if ( V_14 )
goto V_38;
V_14 = F_14 ( V_6 -> V_19 , V_7 + 1 , V_10 , V_12 , V_37 ) ;
if ( V_14 )
goto V_38;
V_38:
V_10 -> V_35 = V_34 ;
return V_14 ;
}
int F_15 ( struct V_5 * V_6 )
{
void * V_39 = NULL , * V_40 = NULL , * V_41 = NULL , * V_42 = NULL ;
struct V_9 * V_43 = NULL , * V_44 = NULL , * V_10 ;
const int V_12 = V_6 -> V_13 ;
int V_14 , V_45 , V_46 ;
F_8 ( L_3 ) ;
V_14 = F_3 ( V_6 , V_33 , & V_39 , & V_43 , & V_41 ) ;
if ( V_14 )
goto V_21;
V_14 = F_3 ( V_6 , V_33 + 1 , & V_40 , & V_44 , & V_42 ) ;
if ( V_14 )
goto V_21;
if ( V_43 ) {
V_45 = ( void * ) V_43 - V_39 ;
if ( ( F_6 ( V_43 -> V_35 ) & V_36 ) &&
( V_45 == 0 && ! V_41 ) ) {
F_8 ( L_4 ) ;
V_10 = V_43 ;
} else if ( V_44 ) {
V_46 = ( void * ) V_44 - V_40 ;
if ( V_45 == V_46 ) {
if ( memcmp ( ( void * ) V_43 + V_47 ,
( void * ) V_44 + V_47 ,
V_22 - V_47 ) )
goto V_29;
V_10 = V_43 ;
} else if ( V_46 + V_12 == V_45 ) {
if ( V_41 )
goto V_29;
V_10 = V_43 ;
} else if ( V_45 == 0 && V_46 + V_12 >= V_6 -> V_17 ) {
if ( V_41 )
goto V_29;
V_10 = V_43 ;
} else
goto V_29;
} else {
if ( V_45 != 0 || V_41 )
goto V_29;
V_10 = V_43 ;
}
} else {
if ( ! V_44 )
goto V_29;
V_46 = ( void * ) V_44 - V_40 ;
if ( V_46 + V_12 + V_12 <= V_6 -> V_17 )
goto V_29;
V_10 = V_44 ;
}
F_16 ( L_5 ,
( V_10 == V_43 ? V_33 : V_33 + 1 ) ) ;
memcpy ( V_6 -> V_48 , V_10 , V_22 ) ;
if ( V_6 -> V_49 ) {
V_6 -> V_50 = F_17 ( V_12 , V_51 ) ;
if ( ! V_6 -> V_50 ) {
V_14 = - V_18 ;
goto V_21;
}
memcpy ( V_6 -> V_50 , V_6 -> V_48 , V_22 ) ;
V_6 -> V_48 -> V_35 |= F_12 ( V_52 ) ;
} else {
V_6 -> V_53 = F_18 ( V_10 -> V_24 . V_54 ) - 1 ;
V_14 = F_11 ( V_6 , V_6 -> V_48 ) ;
if ( V_14 )
goto V_21;
}
F_10 ( V_40 ) ;
F_10 ( V_39 ) ;
return 0 ;
V_29:
V_14 = - V_32 ;
V_21:
F_19 ( L_6 ) ;
if ( V_43 ) {
F_20 ( L_7 ) ;
F_21 ( V_6 , V_43 ) ;
}
if ( V_44 ) {
F_20 ( L_8 ) ;
F_21 ( V_6 , V_44 ) ;
}
F_10 ( V_40 ) ;
F_10 ( V_39 ) ;
return V_14 ;
}
int F_22 ( struct V_5 * V_6 )
{
int V_14 ;
if ( ! V_6 -> V_50 )
return 0 ;
V_6 -> V_50 -> V_35 |= F_12 ( V_52 ) ;
V_6 -> V_48 -> V_35 |= F_12 ( V_52 ) ;
V_14 = F_11 ( V_6 , V_6 -> V_50 ) ;
if ( V_14 )
return V_14 ;
F_23 ( V_6 -> V_50 ) ;
V_6 -> V_50 = NULL ;
return 0 ;
}
static int F_24 ( const struct V_5 * V_6 , void * V_1 , int V_15 )
{
int V_55 , V_56 ;
T_1 * V_3 ;
V_55 = F_25 ( V_15 + 1 , V_6 -> V_57 ) ;
V_56 = V_6 -> V_17 - V_55 ;
V_3 = V_1 + V_55 - V_15 ;
return F_1 ( V_3 , V_56 ) ;
}
static void F_26 ( const struct V_5 * V_6 , void * * V_1 , int V_7 ,
int * V_15 , int * V_2 )
{
int V_55 , V_58 ;
V_7 = V_7 ;
F_8 ( L_9 , V_7 , * V_15 ) ;
F_27 ( ! ( * V_15 & 7 ) ) ;
V_55 = F_25 ( * V_15 , V_6 -> V_59 ) ;
V_58 = V_55 - * V_15 ;
F_28 ( V_6 , * V_1 , V_58 ) ;
* V_15 += V_58 ;
* V_1 += V_58 ;
* V_2 -= V_58 ;
memset ( * V_1 , 0xff , V_6 -> V_17 - V_55 ) ;
}
static int F_29 ( const struct V_5 * V_6 , void * V_1 , int V_2 ,
int V_7 , int V_15 )
{
struct V_23 * V_24 = V_1 ;
int V_60 , V_61 = F_6 ( V_24 -> V_2 ) ;
V_60 = F_25 ( V_15 + V_47 , V_6 -> V_57 ) - V_15 ;
if ( F_1 ( V_1 + V_60 , V_2 - V_60 ) )
return 1 ;
if ( F_30 ( V_6 , V_1 , V_7 , V_15 , 1 , 0 ) != - V_62 ) {
F_8 ( L_10 , V_7 , V_15 ) ;
return 0 ;
}
V_60 = F_25 ( V_15 + V_61 , V_6 -> V_57 ) - V_15 ;
if ( F_1 ( V_1 + V_60 , V_2 - V_60 ) )
return 1 ;
F_8 ( L_11 , V_7 , V_15 + V_60 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_63 * V_64 ,
int V_65 )
{
int V_7 = V_64 -> V_7 , V_66 = V_65 ;
if ( ! F_32 ( & V_64 -> V_67 ) ) {
struct V_68 * V_69 ;
V_69 = F_33 ( V_64 -> V_67 . V_70 ,
struct V_68 , V_71 ) ;
V_66 = V_69 -> V_15 + V_69 -> V_2 ;
}
if ( V_6 -> V_49 && ! V_6 -> V_72 ) {
struct V_73 * V_74 ;
F_8 ( L_12 ,
V_7 , V_65 , V_64 -> V_66 ) ;
V_74 = F_34 ( sizeof( struct V_73 ) , V_75 ) ;
if ( ! V_74 )
return - V_18 ;
V_74 -> V_7 = V_7 ;
V_74 -> V_66 = V_66 ;
F_35 ( & V_74 -> V_71 , & V_6 -> V_76 ) ;
} else {
int V_14 ;
F_8 ( L_13 ,
V_7 , V_65 , V_64 -> V_66 ) ;
if ( V_66 == 0 ) {
V_14 = F_36 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
} else {
int V_2 = F_25 ( V_66 , V_6 -> V_59 ) ;
if ( V_65 ) {
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_64 -> V_1 , 0 ,
V_65 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 > V_66 ) {
int V_58 = V_2 - F_25 ( V_66 , 8 ) ;
if ( V_58 > 0 ) {
void * V_1 = V_64 -> V_1 + V_2 - V_58 ;
F_28 ( V_6 , V_1 , V_58 ) ;
}
}
V_14 = F_14 ( V_6 -> V_19 , V_7 , V_64 -> V_1 , V_2 ,
V_77 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static void F_37 ( struct V_63 * V_64 , int * V_15 )
{
while ( ! F_32 ( & V_64 -> V_67 ) ) {
struct V_68 * V_69 ;
struct V_23 * V_24 ;
V_69 = F_33 ( V_64 -> V_67 . V_70 , struct V_68 ,
V_71 ) ;
V_24 = V_69 -> V_78 ;
if ( V_24 -> V_79 != V_80 )
break;
F_8 ( L_14 ,
V_64 -> V_7 , V_69 -> V_15 ) ;
* V_15 = V_69 -> V_15 ;
F_38 ( & V_69 -> V_71 ) ;
F_23 ( V_69 ) ;
V_64 -> V_81 -= 1 ;
}
}
static void F_39 ( struct V_63 * V_64 , int * V_15 )
{
struct V_68 * V_69 ;
if ( ! F_32 ( & V_64 -> V_67 ) ) {
V_69 = F_33 ( V_64 -> V_67 . V_70 , struct V_68 ,
V_71 ) ;
F_8 ( L_15 , V_64 -> V_7 , V_69 -> V_15 ) ;
* V_15 = V_69 -> V_15 ;
F_38 ( & V_69 -> V_71 ) ;
F_23 ( V_69 ) ;
V_64 -> V_81 -= 1 ;
}
}
struct V_63 * F_40 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 , int V_82 )
{
int V_27 = 0 , V_14 , V_2 = V_6 -> V_17 - V_15 , V_65 = V_15 , V_83 ;
int V_84 = V_82 == - 1 ? 0 : V_6 -> V_85 [ V_82 ] . V_84 ;
struct V_63 * V_64 ;
void * V_1 = V_16 + V_15 ;
F_8 ( L_16 , V_7 , V_15 , V_82 , V_84 ) ;
V_64 = F_41 ( V_6 , V_7 , V_15 , V_16 ) ;
if ( F_42 ( V_64 ) )
return V_64 ;
F_27 ( V_2 >= 8 ) ;
while ( V_2 >= 8 ) {
F_43 ( L_17 ,
V_7 , V_15 , V_2 ) ;
F_44 () ;
V_27 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_27 == V_28 ) {
struct V_23 * V_24 = V_1 ;
int V_86 ;
V_14 = F_45 ( V_6 , V_64 , V_1 , V_15 ) ;
if ( V_14 )
goto error;
V_86 = F_25 ( F_6 ( V_24 -> V_2 ) , 8 ) ;
V_15 += V_86 ;
V_1 += V_86 ;
V_2 -= V_86 ;
} else if ( V_27 > 0 ) {
V_15 += V_27 ;
V_1 += V_27 ;
V_2 -= V_27 ;
} else if ( V_27 == V_87 ||
V_27 == V_88 ||
V_27 == V_89 ||
V_27 == V_90 ) {
F_8 ( L_18 , V_27 ) ;
break;
} else {
F_20 ( L_19 , V_27 ) ;
V_14 = - V_32 ;
goto error;
}
}
if ( V_27 == V_88 || V_27 == V_89 ) {
if ( ! F_24 ( V_6 , V_1 , V_15 ) )
goto V_91;
} else if ( V_27 == V_90 ) {
if ( ! F_29 ( V_6 , V_1 , V_2 , V_7 , V_15 ) )
goto V_91;
} else if ( ! F_1 ( V_1 , V_2 ) ) {
if ( ! F_24 ( V_6 , V_1 , V_15 ) ) {
int V_92 = F_2 ( V_1 , V_2 ) ;
F_19 ( L_20
L_21 , V_7 , V_15 , V_92 ) ;
V_15 += V_92 ;
V_1 += V_92 ;
goto V_93;
}
}
V_83 = F_46 ( V_15 , V_6 -> V_59 ) ;
if ( V_84 )
F_37 ( V_64 , & V_15 ) ;
if ( V_82 == V_94 ) {
while ( V_15 > V_83 )
F_39 ( V_64 , & V_15 ) ;
}
V_1 = V_16 + V_15 ;
V_2 = V_6 -> V_17 - V_15 ;
F_26 ( V_6 , & V_1 , V_7 , & V_15 , & V_2 ) ;
F_47 ( V_6 , V_64 , V_7 , V_15 ) ;
V_14 = F_31 ( V_6 , V_64 , V_65 ) ;
if ( V_14 )
goto error;
return V_64 ;
V_91:
F_20 ( L_22 , V_27 ) ;
F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
V_93:
F_48 ( V_6 , V_7 , V_15 , V_1 ) ;
V_14 = - V_62 ;
error:
F_19 ( L_23 , V_7 ) ;
F_49 ( V_64 ) ;
return F_50 ( V_14 ) ;
}
static int F_51 ( struct V_5 * V_6 , int V_7 , int V_15 ,
unsigned long long * V_95 )
{
struct V_96 * V_97 = NULL ;
int V_14 , V_27 ;
F_8 ( L_24 , V_7 , V_15 ) ;
V_97 = F_17 ( V_98 , V_51 ) ;
if ( ! V_97 )
return - V_18 ;
if ( V_6 -> V_17 - V_15 < V_98 )
goto V_29;
V_14 = F_5 ( V_6 -> V_19 , V_7 , ( void * ) V_97 , V_15 , V_98 ) ;
if ( V_14 && V_14 != - V_20 )
goto V_21;
V_27 = F_7 ( V_6 , V_97 , V_98 , V_7 , V_15 , 0 ) ;
if ( V_27 != V_28 ) {
F_20 ( L_25 ) ;
goto V_29;
}
if ( V_97 -> V_24 . V_30 != V_99 ) {
F_20 ( L_26 , V_97 -> V_24 . V_30 ) ;
goto V_29;
}
if ( F_18 ( V_97 -> V_100 ) != V_6 -> V_100 ) {
F_20 ( L_27 ,
( unsigned long long ) F_18 ( V_97 -> V_100 ) ,
V_6 -> V_100 ) ;
goto V_29;
}
* V_95 = F_18 ( V_97 -> V_24 . V_54 ) ;
F_8 ( L_28 , * V_95 ) ;
F_23 ( V_97 ) ;
return 0 ;
V_29:
V_14 = - V_32 ;
V_21:
F_19 ( L_29 ) ;
F_23 ( V_97 ) ;
return V_14 ;
}
struct V_63 * F_52 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 )
{
struct V_63 * V_64 ;
int V_101 ;
F_8 ( L_30 , V_7 ) ;
V_101 = V_7 + 1 ;
if ( V_101 >= V_102 + V_6 -> V_103 )
V_101 = V_102 ;
if ( V_101 != V_6 -> V_104 ) {
V_64 = F_53 ( V_6 , V_101 , 0 , V_16 , 0 ) ;
if ( F_42 ( V_64 ) )
return V_64 ;
if ( V_64 -> V_81 ) {
struct V_68 * V_69 ;
unsigned long long V_95 = V_6 -> V_95 ;
V_69 = F_33 ( V_64 -> V_67 . V_105 ,
struct V_68 , V_71 ) ;
if ( V_95 == 0 ) {
int V_14 ;
V_14 = F_51 ( V_6 , V_7 , V_15 , & V_95 ) ;
if ( V_14 ) {
F_49 ( V_64 ) ;
return F_50 ( V_14 ) ;
}
}
if ( V_69 -> V_54 > V_95 ) {
F_19 ( L_31
L_32 , V_7 ) ;
F_49 ( V_64 ) ;
return F_50 ( - V_62 ) ;
}
}
F_49 ( V_64 ) ;
}
return F_40 ( V_6 , V_7 , V_15 , V_16 , - 1 ) ;
}
static int F_54 ( const struct V_5 * V_6 , int V_7 , int V_15 ,
void * V_16 )
{
int V_2 = V_6 -> V_57 , V_14 ;
if ( V_15 + V_2 > V_6 -> V_17 )
V_2 = V_6 -> V_17 - V_15 ;
if ( ! V_2 )
return 0 ;
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_16 , V_15 , V_2 ) ;
if ( V_14 || ! F_1 ( V_16 , V_2 ) ) {
F_8 ( L_33 , V_7 , V_15 ) ;
if ( V_15 == 0 )
return F_36 ( V_6 , V_7 ) ;
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_16 , 0 , V_15 ) ;
if ( V_14 )
return V_14 ;
return F_14 ( V_6 -> V_19 , V_7 , V_16 , V_15 , V_77 ) ;
}
return 0 ;
}
int F_55 ( const struct V_5 * V_6 , void * V_16 )
{
int V_14 ;
F_27 ( ! V_6 -> V_49 || V_6 -> V_72 ) ;
F_8 ( L_34 , V_6 -> V_106 , V_6 -> V_107 ) ;
V_14 = F_54 ( V_6 , V_6 -> V_106 , V_6 -> V_107 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_35 , V_6 -> V_108 , V_6 -> V_109 ) ;
V_14 = F_54 ( V_6 , V_6 -> V_108 , V_6 -> V_109 , V_16 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_56 ( const struct V_5 * V_6 ,
struct V_73 * V_74 , void * V_16 )
{
int V_14 , V_7 = V_74 -> V_7 , V_15 = 0 , V_2 = V_74 -> V_66 , V_110 = 1 ;
void * V_1 = V_16 ;
F_8 ( L_36 , V_7 , V_2 ) ;
if ( V_2 == 0 ) {
V_14 = F_36 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_1 , V_15 , V_2 ) ;
if ( V_14 && V_14 != - V_20 )
return V_14 ;
while ( V_2 >= 8 ) {
int V_27 ;
F_44 () ;
V_27 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , V_110 ) ;
if ( V_27 == V_28 ) {
struct V_23 * V_24 = V_1 ;
int V_86 ;
V_86 = F_25 ( F_6 ( V_24 -> V_2 ) , 8 ) ;
V_15 += V_86 ;
V_1 += V_86 ;
V_2 -= V_86 ;
continue;
}
if ( V_27 > 0 ) {
V_15 += V_27 ;
V_1 += V_27 ;
V_2 -= V_27 ;
continue;
}
if ( V_27 == V_87 ) {
F_19 ( L_37 ,
V_7 , V_15 ) ;
return - V_62 ;
}
if ( V_110 ) {
V_110 = 0 ;
continue;
}
F_48 ( V_6 , V_7 , V_15 , V_1 ) ;
return - V_62 ;
}
V_2 = F_25 ( V_74 -> V_66 , V_6 -> V_59 ) ;
if ( V_2 > V_74 -> V_66 ) {
int V_58 = V_2 - F_25 ( V_74 -> V_66 , 8 ) ;
if ( V_58 > 0 ) {
V_1 = V_6 -> V_16 + V_2 - V_58 ;
F_28 ( V_6 , V_1 , V_58 ) ;
}
}
V_14 = F_14 ( V_6 -> V_19 , V_7 , V_16 , V_2 , V_77 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_38 , V_7 ) ;
return 0 ;
}
int F_57 ( const struct V_5 * V_6 , void * V_16 )
{
F_8 ( L_3 ) ;
while ( ! F_32 ( & V_6 -> V_76 ) ) {
struct V_73 * V_74 ;
int V_14 ;
V_74 = F_33 ( V_6 -> V_76 . V_105 ,
struct V_73 , V_71 ) ;
V_14 = F_56 ( V_6 , V_74 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_38 ( & V_74 -> V_71 ) ;
F_23 ( V_74 ) ;
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
F_61 ( V_6 , & V_6 -> V_111 ) ;
return V_7 ;
}
V_14 = F_62 ( V_6 , V_7 , V_112 , V_112 , 0 ,
V_113 , 0 ) ;
if ( V_14 )
return V_14 ;
V_6 -> V_114 = V_7 ;
F_8 ( L_40 , V_7 ) ;
return F_63 ( V_6 ) ;
}
int F_64 ( struct V_5 * V_6 )
{
struct V_115 * V_116 = & V_6 -> V_85 [ V_94 ] . V_116 ;
struct V_117 V_118 ;
int V_14 ;
F_8 ( L_41 , V_116 -> V_7 , V_116 -> V_15 ) ;
V_6 -> V_114 = - 1 ;
if ( V_116 -> V_7 == - 1 || V_116 -> V_15 == V_6 -> V_17 )
return F_58 ( V_6 ) ;
V_14 = F_65 ( V_6 , & V_118 , V_116 -> V_15 , 2 ) ;
if ( V_14 ) {
if ( V_14 != - V_119 )
return V_14 ;
F_8 ( L_42 ) ;
return F_58 ( V_6 ) ;
}
F_27 ( ! ( V_118 . V_35 & V_113 ) ) ;
F_27 ( V_118 . free + V_118 . V_120 >= V_116 -> V_15 ) ;
F_8 ( L_43 ) ;
V_14 = F_63 ( V_6 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_44 , V_118 . V_7 ) ;
F_66 ( & V_116 -> V_121 , V_116 -> V_82 ) ;
V_14 = F_67 ( V_6 , & V_118 ) ;
if ( V_14 >= 0 ) {
int V_122 = F_68 ( V_116 ) ;
if ( V_122 )
V_14 = V_122 ;
}
F_69 ( & V_116 -> V_121 ) ;
if ( V_14 < 0 ) {
F_20 ( L_45 , V_14 ) ;
if ( V_14 == - V_123 )
V_14 = - V_32 ;
return V_14 ;
}
F_27 ( V_14 == V_124 ) ;
if ( V_14 != V_124 )
return - V_32 ;
V_14 = F_36 ( V_6 , V_6 -> V_114 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_46 , V_118 . V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 , T_3 V_125 , T_4 V_126 ,
T_4 V_127 , int V_128 )
{
struct V_129 * * V_3 = & V_6 -> V_130 . V_129 , * V_131 = NULL ;
struct V_132 * V_133 ;
while ( * V_3 ) {
V_131 = * V_3 ;
V_133 = F_71 ( V_131 , struct V_132 , V_134 ) ;
if ( V_125 < V_133 -> V_125 )
V_3 = & ( * V_3 ) -> V_135 ;
else
V_3 = & ( * V_3 ) -> V_136 ;
}
V_133 = F_34 ( sizeof( struct V_132 ) , V_51 ) ;
if ( ! V_133 )
return - V_18 ;
V_133 -> V_125 = V_125 ;
V_133 -> V_126 = V_126 ;
V_133 -> V_127 = V_127 ;
V_133 -> V_128 = V_128 ;
F_72 ( & V_133 -> V_134 , V_131 , V_3 ) ;
F_73 ( & V_133 -> V_134 , & V_6 -> V_130 ) ;
return 0 ;
}
static struct V_132 * F_74 ( struct V_5 * V_6 , T_3 V_125 )
{
struct V_129 * V_3 = V_6 -> V_130 . V_129 ;
struct V_132 * V_133 ;
while ( V_3 ) {
V_133 = F_71 ( V_3 , struct V_132 , V_134 ) ;
if ( V_125 < V_133 -> V_125 )
V_3 = V_3 -> V_135 ;
else if ( V_125 > V_133 -> V_125 )
V_3 = V_3 -> V_136 ;
else
return V_133 ;
}
return NULL ;
}
static void F_75 ( struct V_5 * V_6 , T_3 V_125 )
{
struct V_132 * V_133 = F_74 ( V_6 , V_125 ) ;
if ( ! V_133 )
return;
F_76 ( & V_133 -> V_134 , & V_6 -> V_130 ) ;
F_23 ( V_133 ) ;
}
void F_77 ( struct V_5 * V_6 )
{
struct V_129 * V_137 = V_6 -> V_130 . V_129 ;
struct V_132 * V_133 ;
while ( V_137 ) {
if ( V_137 -> V_135 ) {
V_137 = V_137 -> V_135 ;
continue;
} else if ( V_137 -> V_136 ) {
V_137 = V_137 -> V_136 ;
continue;
}
V_133 = F_71 ( V_137 , struct V_132 , V_134 ) ;
if ( V_133 -> V_138 )
F_78 ( V_133 -> V_138 ) ;
V_137 = F_79 ( V_137 ) ;
if ( V_137 ) {
if ( V_137 -> V_135 == & V_133 -> V_134 )
V_137 -> V_135 = NULL ;
else
V_137 -> V_136 = NULL ;
}
F_23 ( V_133 ) ;
}
V_6 -> V_130 = V_139 ;
}
int F_80 ( struct V_5 * V_6 , union V_140 * V_141 ,
int V_142 , T_4 V_143 )
{
T_3 V_125 = F_81 ( V_6 , V_141 ) ;
struct V_132 * V_133 ;
int V_14 ;
switch ( F_82 ( V_6 , V_141 ) ) {
case V_144 :
if ( V_142 )
F_75 ( V_6 , V_125 ) ;
else {
V_133 = F_74 ( V_6 , V_125 ) ;
if ( V_133 ) {
V_133 -> V_126 = V_143 ;
V_133 -> V_128 = 1 ;
} else {
V_14 = F_70 ( V_6 , V_125 , V_143 , 0 , 1 ) ;
if ( V_14 )
return V_14 ;
}
}
break;
case V_145 :
V_133 = F_74 ( V_6 , V_125 ) ;
if ( V_133 ) {
if ( V_143 > V_133 -> V_127 )
V_133 -> V_127 = V_143 ;
} else {
V_14 = F_70 ( V_6 , V_125 , 0 , V_143 , 0 ) ;
if ( V_14 )
return V_14 ;
}
break;
case V_146 :
V_133 = F_74 ( V_6 , V_125 ) ;
if ( V_133 )
V_133 -> V_127 = V_143 ;
break;
}
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , struct V_132 * V_133 )
{
struct V_147 * V_148 = V_6 -> V_16 ;
unsigned char * V_3 ;
union V_140 V_141 ;
int V_14 , V_7 , V_15 , V_2 ;
T_4 V_126 ;
T_5 V_149 ;
F_84 ( V_6 , & V_141 , V_133 -> V_125 ) ;
V_14 = F_85 ( V_6 , & V_141 , V_148 , & V_7 , & V_15 ) ;
if ( V_14 )
goto V_38;
V_126 = F_18 ( V_148 -> V_150 ) ;
if ( V_126 >= V_133 -> V_127 )
return 0 ;
V_14 = F_5 ( V_6 -> V_19 , V_7 , V_6 -> V_16 , 0 , V_6 -> V_17 ) ;
if ( V_14 )
goto V_38;
V_148 = V_6 -> V_16 + V_15 ;
V_148 -> V_150 = F_86 ( V_133 -> V_127 ) ;
V_2 = F_6 ( V_148 -> V_24 . V_2 ) ;
V_149 = F_87 ( V_151 , ( void * ) V_148 + 8 , V_2 - 8 ) ;
V_148 -> V_24 . V_149 = F_12 ( V_149 ) ;
V_3 = V_6 -> V_16 ;
V_2 = V_6 -> V_17 - 1 ;
while ( V_3 [ V_2 ] == 0xff )
V_2 -= 1 ;
V_2 = F_25 ( V_2 + 1 , V_6 -> V_59 ) ;
V_14 = F_14 ( V_6 -> V_19 , V_7 , V_6 -> V_16 , V_2 , V_77 ) ;
if ( V_14 )
goto V_38;
F_8 ( L_47 ,
( unsigned long ) V_133 -> V_125 , V_7 , V_15 , V_126 , V_133 -> V_127 ) ;
return 0 ;
V_38:
F_88 ( L_48 ,
( unsigned long ) V_133 -> V_125 , V_133 -> V_126 , V_133 -> V_127 , V_14 ) ;
return V_14 ;
}
int F_89 ( struct V_5 * V_6 )
{
struct V_129 * V_137 = F_90 ( & V_6 -> V_130 ) ;
while ( V_137 ) {
struct V_132 * V_133 ;
int V_14 ;
V_133 = F_71 ( V_137 , struct V_132 , V_134 ) ;
if ( ! V_133 -> V_128 ) {
union V_140 V_141 ;
F_84 ( V_6 , & V_141 , V_133 -> V_125 ) ;
V_14 = F_91 ( V_6 , & V_141 , V_6 -> V_16 ) ;
if ( V_14 && V_14 != - V_152 )
return V_14 ;
if ( V_14 == - V_152 ) {
F_8 ( L_49 ,
( unsigned long ) V_133 -> V_125 ) ;
V_14 = F_92 ( V_6 , V_133 -> V_125 ) ;
if ( V_14 )
return V_14 ;
} else {
struct V_147 * V_148 = V_6 -> V_16 ;
V_133 -> V_128 = 1 ;
V_133 -> V_126 = F_18 ( V_148 -> V_150 ) ;
}
}
if ( V_133 -> V_128 && V_133 -> V_126 < V_133 -> V_127 ) {
if ( V_6 -> V_49 ) {
struct V_138 * V_138 ;
struct V_153 * V_154 ;
F_27 ( ! V_133 -> V_138 ) ;
V_138 = F_93 ( V_6 -> V_155 , V_133 -> V_125 ) ;
if ( F_42 ( V_138 ) )
return F_94 ( V_138 ) ;
V_154 = V_153 ( V_138 ) ;
if ( V_138 -> V_126 < V_133 -> V_127 ) {
F_8 ( L_50 ,
( unsigned long ) V_133 -> V_125 ,
V_138 -> V_126 , V_133 -> V_127 ) ;
V_138 -> V_126 = V_133 -> V_127 ;
V_154 -> V_156 = V_133 -> V_127 ;
V_154 -> V_157 = V_133 -> V_127 ;
V_133 -> V_138 = V_138 ;
V_137 = F_95 ( V_137 ) ;
continue;
}
F_78 ( V_138 ) ;
} else {
V_14 = F_83 ( V_6 , V_133 ) ;
if ( V_14 )
return V_14 ;
if ( V_133 -> V_138 )
F_78 ( V_133 -> V_138 ) ;
}
}
V_137 = F_95 ( V_137 ) ;
F_76 ( & V_133 -> V_134 , & V_6 -> V_130 ) ;
F_23 ( V_133 ) ;
}
return 0 ;
}
