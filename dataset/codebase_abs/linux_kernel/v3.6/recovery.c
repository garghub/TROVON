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
V_14 = F_14 ( V_6 , V_7 , V_10 , V_12 ) ;
if ( V_14 )
goto V_36;
V_14 = F_14 ( V_6 , V_7 + 1 , V_10 , V_12 ) ;
if ( V_14 )
goto V_36;
V_36:
V_10 -> V_34 = V_33 ;
return V_14 ;
}
int F_15 ( struct V_5 * V_6 )
{
void * V_37 = NULL , * V_38 = NULL , * V_39 = NULL , * V_40 = NULL ;
struct V_9 * V_41 = NULL , * V_42 = NULL , * V_10 ;
const int V_12 = V_6 -> V_13 ;
int V_14 , V_43 , V_44 ;
F_8 ( L_3 ) ;
V_14 = F_3 ( V_6 , V_32 , & V_37 , & V_41 , & V_39 ) ;
if ( V_14 )
goto V_20;
V_14 = F_3 ( V_6 , V_32 + 1 , & V_38 , & V_42 , & V_40 ) ;
if ( V_14 )
goto V_20;
if ( V_41 ) {
V_43 = ( void * ) V_41 - V_37 ;
if ( ( F_6 ( V_41 -> V_34 ) & V_35 ) &&
( V_43 == 0 && ! V_39 ) ) {
F_8 ( L_4 ) ;
V_10 = V_41 ;
} else if ( V_42 ) {
V_44 = ( void * ) V_42 - V_38 ;
if ( V_43 == V_44 ) {
if ( memcmp ( ( void * ) V_41 + V_45 ,
( void * ) V_42 + V_45 ,
V_21 - V_45 ) )
goto V_28;
V_10 = V_41 ;
} else if ( V_44 + V_12 == V_43 ) {
if ( V_39 )
goto V_28;
V_10 = V_41 ;
} else if ( V_43 == 0 &&
V_6 -> V_17 - V_44 - V_12 < V_12 ) {
if ( V_39 )
goto V_28;
V_10 = V_41 ;
} else
goto V_28;
} else {
if ( V_43 != 0 || V_39 )
goto V_28;
V_10 = V_41 ;
}
} else {
if ( ! V_42 )
goto V_28;
V_44 = ( void * ) V_42 - V_38 ;
if ( V_44 + V_12 + V_12 <= V_6 -> V_17 )
goto V_28;
V_10 = V_42 ;
}
F_16 ( L_5 ,
( V_10 == V_41 ? V_32 : V_32 + 1 ) ) ;
memcpy ( V_6 -> V_46 , V_10 , V_21 ) ;
if ( V_6 -> V_47 ) {
V_6 -> V_48 = F_17 ( V_12 , V_49 ) ;
if ( ! V_6 -> V_48 ) {
V_14 = - V_18 ;
goto V_20;
}
memcpy ( V_6 -> V_48 , V_6 -> V_46 , V_21 ) ;
V_6 -> V_46 -> V_34 |= F_12 ( V_50 ) ;
} else {
V_6 -> V_51 = F_18 ( V_10 -> V_23 . V_52 ) - 1 ;
V_14 = F_11 ( V_6 , V_6 -> V_46 ) ;
if ( V_14 )
goto V_20;
}
F_10 ( V_38 ) ;
F_10 ( V_37 ) ;
return 0 ;
V_28:
V_14 = - V_31 ;
V_20:
F_19 ( L_6 ) ;
if ( V_41 ) {
F_19 ( L_7 ) ;
F_20 ( V_6 , V_41 ) ;
}
if ( V_42 ) {
F_19 ( L_8 ) ;
F_20 ( V_6 , V_42 ) ;
}
F_10 ( V_38 ) ;
F_10 ( V_37 ) ;
return V_14 ;
}
int F_21 ( struct V_5 * V_6 )
{
int V_14 ;
if ( ! V_6 -> V_48 )
return 0 ;
V_6 -> V_48 -> V_34 |= F_12 ( V_50 ) ;
V_6 -> V_46 -> V_34 |= F_12 ( V_50 ) ;
V_14 = F_11 ( V_6 , V_6 -> V_48 ) ;
if ( V_14 )
return V_14 ;
F_22 ( V_6 -> V_48 ) ;
V_6 -> V_48 = NULL ;
return 0 ;
}
static int F_23 ( const struct V_5 * V_6 , void * V_1 , int V_15 )
{
int V_53 , V_54 ;
T_1 * V_3 ;
V_53 = F_24 ( V_15 + 1 , V_6 -> V_55 ) ;
V_54 = V_6 -> V_17 - V_53 ;
V_3 = V_1 + V_53 - V_15 ;
return F_1 ( V_3 , V_54 ) ;
}
static void F_25 ( const struct V_5 * V_6 , void * * V_1 , int V_7 ,
int * V_15 , int * V_2 )
{
int V_53 , V_56 ;
V_7 = V_7 ;
F_8 ( L_9 , V_7 , * V_15 ) ;
F_26 ( ! ( * V_15 & 7 ) ) ;
V_53 = F_24 ( * V_15 , V_6 -> V_57 ) ;
V_56 = V_53 - * V_15 ;
F_27 ( V_6 , * V_1 , V_56 ) ;
* V_15 += V_56 ;
* V_1 += V_56 ;
* V_2 -= V_56 ;
memset ( * V_1 , 0xff , V_6 -> V_17 - V_53 ) ;
}
static int F_28 ( const struct V_5 * V_6 , void * V_1 , int V_2 ,
int V_7 , int V_15 )
{
struct V_22 * V_23 = V_1 ;
int V_58 , V_59 = F_6 ( V_23 -> V_2 ) ;
V_58 = F_24 ( V_15 + V_45 , V_6 -> V_55 ) - V_15 ;
if ( F_1 ( V_1 + V_58 , V_2 - V_58 ) )
return 1 ;
if ( F_29 ( V_6 , V_1 , V_7 , V_15 , 1 , 0 ) != - V_60 ) {
F_8 ( L_10 , V_7 , V_15 ) ;
return 0 ;
}
V_58 = F_24 ( V_15 + V_59 , V_6 -> V_55 ) - V_15 ;
if ( F_1 ( V_1 + V_58 , V_2 - V_58 ) )
return 1 ;
F_8 ( L_11 , V_7 , V_15 + V_58 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_61 * V_62 ,
int V_63 )
{
int V_7 = V_62 -> V_7 , V_64 = V_63 ;
if ( ! F_31 ( & V_62 -> V_65 ) ) {
struct V_66 * V_67 ;
V_67 = F_32 ( V_62 -> V_65 . V_68 ,
struct V_66 , V_69 ) ;
V_64 = V_67 -> V_15 + V_67 -> V_2 ;
}
if ( V_6 -> V_47 && ! V_6 -> V_70 ) {
struct V_71 * V_72 ;
F_8 ( L_12 ,
V_7 , V_63 , V_62 -> V_64 ) ;
V_72 = F_33 ( sizeof( struct V_71 ) , V_73 ) ;
if ( ! V_72 )
return - V_18 ;
V_72 -> V_7 = V_7 ;
V_72 -> V_64 = V_64 ;
F_34 ( & V_72 -> V_69 , & V_6 -> V_74 ) ;
} else {
int V_14 ;
F_8 ( L_13 ,
V_7 , V_63 , V_62 -> V_64 ) ;
if ( V_64 == 0 ) {
V_14 = F_35 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
} else {
int V_2 = F_24 ( V_64 , V_6 -> V_57 ) ;
if ( V_63 ) {
V_14 = F_5 ( V_6 , V_7 , V_62 -> V_1 , 0 ,
V_63 , 1 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_2 > V_64 ) {
int V_56 = V_2 - F_24 ( V_64 , 8 ) ;
if ( V_56 > 0 ) {
void * V_1 = V_62 -> V_1 + V_2 - V_56 ;
F_27 ( V_6 , V_1 , V_56 ) ;
}
}
V_14 = F_14 ( V_6 , V_7 , V_62 -> V_1 , V_2 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static void F_36 ( struct V_61 * V_62 , int * V_15 )
{
while ( ! F_31 ( & V_62 -> V_65 ) ) {
struct V_66 * V_67 ;
struct V_22 * V_23 ;
V_67 = F_32 ( V_62 -> V_65 . V_68 , struct V_66 ,
V_69 ) ;
V_23 = V_67 -> V_75 ;
if ( V_23 -> V_76 != V_77 )
break;
F_8 ( L_14 ,
V_62 -> V_7 , V_67 -> V_15 ) ;
* V_15 = V_67 -> V_15 ;
F_37 ( & V_67 -> V_69 ) ;
F_22 ( V_67 ) ;
V_62 -> V_78 -= 1 ;
}
}
static void F_38 ( struct V_61 * V_62 , int * V_15 )
{
struct V_66 * V_67 ;
if ( ! F_31 ( & V_62 -> V_65 ) ) {
V_67 = F_32 ( V_62 -> V_65 . V_68 , struct V_66 ,
V_69 ) ;
F_8 ( L_15 , V_62 -> V_7 , V_67 -> V_15 ) ;
* V_15 = V_67 -> V_15 ;
F_37 ( & V_67 -> V_69 ) ;
F_22 ( V_67 ) ;
V_62 -> V_78 -= 1 ;
}
}
struct V_61 * F_39 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 , int V_79 )
{
int V_26 = 0 , V_14 , V_2 = V_6 -> V_17 - V_15 , V_63 = V_15 , V_80 ;
int V_81 = V_79 == - 1 ? 0 : V_6 -> V_82 [ V_79 ] . V_81 ;
struct V_61 * V_62 ;
void * V_1 = V_16 + V_15 ;
F_8 ( L_16 , V_7 , V_15 , V_79 , V_81 ) ;
V_62 = F_40 ( V_6 , V_7 , V_15 , V_16 ) ;
if ( F_41 ( V_62 ) )
return V_62 ;
F_26 ( V_2 >= 8 ) ;
while ( V_2 >= 8 ) {
F_42 ( L_17 ,
V_7 , V_15 , V_2 ) ;
F_43 () ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
if ( V_26 == V_27 ) {
struct V_22 * V_23 = V_1 ;
int V_83 ;
V_14 = F_44 ( V_6 , V_62 , V_1 , V_15 ) ;
if ( V_14 )
goto error;
V_83 = F_24 ( F_6 ( V_23 -> V_2 ) , 8 ) ;
V_15 += V_83 ;
V_1 += V_83 ;
V_2 -= V_83 ;
} else if ( V_26 > 0 ) {
V_15 += V_26 ;
V_1 += V_26 ;
V_2 -= V_26 ;
} else if ( V_26 == V_84 ||
V_26 == V_85 ||
V_26 == V_86 ||
V_26 == V_87 ) {
F_8 ( L_18 ,
V_26 , V_7 , V_15 ) ;
break;
} else {
F_19 ( L_19 , V_26 ) ;
V_14 = - V_31 ;
goto error;
}
}
if ( V_26 == V_85 || V_26 == V_86 ) {
if ( ! F_23 ( V_6 , V_1 , V_15 ) )
goto V_88;
} else if ( V_26 == V_87 ) {
if ( ! F_28 ( V_6 , V_1 , V_2 , V_7 , V_15 ) )
goto V_88;
} else if ( ! F_1 ( V_1 , V_2 ) ) {
if ( ! F_23 ( V_6 , V_1 , V_15 ) ) {
int V_89 = F_2 ( V_1 , V_2 ) ;
F_19 ( L_20
L_21 , V_7 , V_15 , V_89 ) ;
V_15 += V_89 ;
V_1 += V_89 ;
goto V_90;
}
}
V_80 = F_45 ( V_15 , V_6 -> V_57 ) ;
if ( V_81 )
F_36 ( V_62 , & V_15 ) ;
if ( V_79 == V_91 ) {
while ( V_15 > V_80 )
F_38 ( V_62 , & V_15 ) ;
}
V_1 = V_16 + V_15 ;
V_2 = V_6 -> V_17 - V_15 ;
F_25 ( V_6 , & V_1 , V_7 , & V_15 , & V_2 ) ;
F_46 ( V_6 , V_62 , V_7 , V_15 ) ;
V_14 = F_30 ( V_6 , V_62 , V_63 ) ;
if ( V_14 )
goto error;
return V_62 ;
V_88:
F_19 ( L_22 , V_26 ) ;
F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , 1 ) ;
V_90:
F_47 ( V_6 , V_7 , V_15 , V_1 ) ;
V_14 = - V_60 ;
error:
F_19 ( L_23 , V_7 ) ;
F_48 ( V_62 ) ;
return F_49 ( V_14 ) ;
}
static int F_50 ( struct V_5 * V_6 , int V_7 , int V_15 ,
unsigned long long * V_92 )
{
struct V_93 * V_94 = NULL ;
int V_14 , V_26 ;
F_8 ( L_24 , V_7 , V_15 ) ;
V_94 = F_17 ( V_95 , V_49 ) ;
if ( ! V_94 )
return - V_18 ;
if ( V_6 -> V_17 - V_15 < V_95 )
goto V_28;
V_14 = F_5 ( V_6 , V_7 , ( void * ) V_94 , V_15 ,
V_95 , 0 ) ;
if ( V_14 && V_14 != - V_19 )
goto V_20;
V_26 = F_7 ( V_6 , V_94 , V_95 , V_7 , V_15 , 0 ) ;
if ( V_26 != V_27 ) {
F_19 ( L_25 ) ;
goto V_28;
}
if ( V_94 -> V_23 . V_29 != V_96 ) {
F_19 ( L_26 , V_94 -> V_23 . V_29 ) ;
goto V_28;
}
if ( F_18 ( V_94 -> V_97 ) != V_6 -> V_97 ) {
F_19 ( L_27 ,
( unsigned long long ) F_18 ( V_94 -> V_97 ) ,
V_6 -> V_97 ) ;
goto V_28;
}
* V_92 = F_18 ( V_94 -> V_23 . V_52 ) ;
F_8 ( L_28 , * V_92 ) ;
F_22 ( V_94 ) ;
return 0 ;
V_28:
V_14 = - V_31 ;
V_20:
F_19 ( L_29 ) ;
F_22 ( V_94 ) ;
return V_14 ;
}
struct V_61 * F_51 ( struct V_5 * V_6 , int V_7 ,
int V_15 , void * V_16 )
{
struct V_61 * V_62 ;
int V_98 ;
F_8 ( L_30 , V_7 ) ;
V_98 = V_7 + 1 ;
if ( V_98 >= V_99 + V_6 -> V_100 )
V_98 = V_99 ;
if ( V_98 != V_6 -> V_101 ) {
V_62 = F_52 ( V_6 , V_98 , 0 , V_16 , 0 ) ;
if ( F_41 ( V_62 ) )
return V_62 ;
if ( V_62 -> V_78 ) {
struct V_66 * V_67 ;
unsigned long long V_92 = V_6 -> V_92 ;
V_67 = F_32 ( V_62 -> V_65 . V_102 ,
struct V_66 , V_69 ) ;
if ( V_92 == 0 ) {
int V_14 ;
V_14 = F_50 ( V_6 , V_7 , V_15 , & V_92 ) ;
if ( V_14 ) {
F_48 ( V_62 ) ;
return F_49 ( V_14 ) ;
}
}
if ( V_67 -> V_52 > V_92 ) {
F_19 ( L_31
L_32 , V_7 ) ;
F_48 ( V_62 ) ;
return F_49 ( - V_60 ) ;
}
}
F_48 ( V_62 ) ;
}
return F_39 ( V_6 , V_7 , V_15 , V_16 , - 1 ) ;
}
static int F_53 ( struct V_5 * V_6 , int V_7 , int V_15 , void * V_16 )
{
int V_2 = V_6 -> V_55 , V_14 ;
if ( V_15 + V_2 > V_6 -> V_17 )
V_2 = V_6 -> V_17 - V_15 ;
if ( ! V_2 )
return 0 ;
V_14 = F_5 ( V_6 , V_7 , V_16 , V_15 , V_2 , 1 ) ;
if ( V_14 || ! F_1 ( V_16 , V_2 ) ) {
F_8 ( L_33 , V_7 , V_15 ) ;
if ( V_15 == 0 )
return F_35 ( V_6 , V_7 ) ;
V_14 = F_5 ( V_6 , V_7 , V_16 , 0 , V_15 , 1 ) ;
if ( V_14 )
return V_14 ;
return F_14 ( V_6 , V_7 , V_16 , V_15 ) ;
}
return 0 ;
}
int F_54 ( struct V_5 * V_6 , void * V_16 )
{
int V_14 ;
F_26 ( ! V_6 -> V_47 || V_6 -> V_70 ) ;
F_8 ( L_34 , V_6 -> V_103 , V_6 -> V_104 ) ;
V_14 = F_53 ( V_6 , V_6 -> V_103 , V_6 -> V_104 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_35 , V_6 -> V_105 , V_6 -> V_106 ) ;
V_14 = F_53 ( V_6 , V_6 -> V_105 , V_6 -> V_106 , V_16 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_71 * V_72 , void * V_16 )
{
int V_14 , V_7 = V_72 -> V_7 , V_15 = 0 , V_2 = V_72 -> V_64 , V_107 = 1 ;
void * V_1 = V_16 ;
F_8 ( L_36 , V_7 , V_2 ) ;
if ( V_2 == 0 ) {
V_14 = F_35 ( V_6 , V_7 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
V_14 = F_5 ( V_6 , V_7 , V_1 , V_15 , V_2 , 0 ) ;
if ( V_14 && V_14 != - V_19 )
return V_14 ;
while ( V_2 >= 8 ) {
int V_26 ;
F_43 () ;
V_26 = F_7 ( V_6 , V_1 , V_2 , V_7 , V_15 , V_107 ) ;
if ( V_26 == V_27 ) {
struct V_22 * V_23 = V_1 ;
int V_83 ;
V_83 = F_24 ( F_6 ( V_23 -> V_2 ) , 8 ) ;
V_15 += V_83 ;
V_1 += V_83 ;
V_2 -= V_83 ;
continue;
}
if ( V_26 > 0 ) {
V_15 += V_26 ;
V_1 += V_26 ;
V_2 -= V_26 ;
continue;
}
if ( V_26 == V_84 ) {
F_19 ( L_37 ,
V_7 , V_15 ) ;
return - V_60 ;
}
if ( V_107 ) {
V_107 = 0 ;
continue;
}
F_47 ( V_6 , V_7 , V_15 , V_1 ) ;
return - V_60 ;
}
V_2 = F_24 ( V_72 -> V_64 , V_6 -> V_57 ) ;
if ( V_2 > V_72 -> V_64 ) {
int V_56 = V_2 - F_24 ( V_72 -> V_64 , 8 ) ;
if ( V_56 > 0 ) {
V_1 = V_6 -> V_16 + V_2 - V_56 ;
F_27 ( V_6 , V_1 , V_56 ) ;
}
}
V_14 = F_14 ( V_6 , V_7 , V_16 , V_2 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_38 , V_7 ) ;
return 0 ;
}
int F_56 ( struct V_5 * V_6 , void * V_16 )
{
F_8 ( L_3 ) ;
while ( ! F_31 ( & V_6 -> V_74 ) ) {
struct V_71 * V_72 ;
int V_14 ;
V_72 = F_32 ( V_6 -> V_74 . V_102 ,
struct V_71 , V_69 ) ;
V_14 = F_55 ( V_6 , V_72 , V_16 ) ;
if ( V_14 )
return V_14 ;
F_37 ( & V_72 -> V_69 ) ;
F_22 ( V_72 ) ;
}
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
int V_7 , V_14 ;
V_7 = F_58 ( V_6 ) ;
if ( V_7 < 0 ) {
F_19 ( L_39 ) ;
F_59 ( V_6 ) ;
F_60 ( V_6 , & V_6 -> V_108 ) ;
return V_7 ;
}
V_14 = F_61 ( V_6 , V_7 , V_109 , V_109 , 0 ,
V_110 , 0 ) ;
if ( V_14 )
return V_14 ;
V_6 -> V_111 = V_7 ;
F_8 ( L_40 , V_7 ) ;
return F_62 ( V_6 ) ;
}
int F_63 ( struct V_5 * V_6 )
{
struct V_112 * V_113 = & V_6 -> V_82 [ V_91 ] . V_113 ;
struct V_114 V_115 ;
int V_14 ;
F_8 ( L_41 , V_113 -> V_7 , V_113 -> V_15 ) ;
V_6 -> V_111 = - 1 ;
if ( V_113 -> V_7 == - 1 || V_113 -> V_15 == V_6 -> V_17 )
return F_57 ( V_6 ) ;
V_14 = F_64 ( V_6 , & V_115 , V_113 -> V_15 , 2 ) ;
if ( V_14 ) {
if ( V_14 != - V_116 )
return V_14 ;
F_8 ( L_42 ) ;
return F_57 ( V_6 ) ;
}
F_26 ( ! ( V_115 . V_34 & V_110 ) ) ;
F_26 ( V_115 . free + V_115 . V_117 >= V_113 -> V_15 ) ;
F_8 ( L_43 ) ;
V_14 = F_62 ( V_6 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_44 , V_115 . V_7 ) ;
F_65 ( & V_113 -> V_118 , V_113 -> V_79 ) ;
V_14 = F_66 ( V_6 , & V_115 ) ;
if ( V_14 >= 0 ) {
int V_119 = F_67 ( V_113 ) ;
if ( V_119 )
V_14 = V_119 ;
}
F_68 ( & V_113 -> V_118 ) ;
if ( V_14 < 0 ) {
F_19 ( L_45 , V_14 ) ;
if ( V_14 == - V_120 )
V_14 = - V_31 ;
return V_14 ;
}
F_26 ( V_14 == V_121 ) ;
if ( V_14 != V_121 )
return - V_31 ;
V_14 = F_35 ( V_6 , V_6 -> V_111 ) ;
if ( V_14 )
return V_14 ;
F_8 ( L_46 , V_115 . V_7 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 , T_3 V_122 , T_4 V_123 ,
T_4 V_124 , int V_125 )
{
struct V_126 * * V_3 = & V_6 -> V_127 . V_126 , * V_128 = NULL ;
struct V_129 * V_130 ;
while ( * V_3 ) {
V_128 = * V_3 ;
V_130 = F_70 ( V_128 , struct V_129 , V_131 ) ;
if ( V_122 < V_130 -> V_122 )
V_3 = & ( * V_3 ) -> V_132 ;
else
V_3 = & ( * V_3 ) -> V_133 ;
}
V_130 = F_33 ( sizeof( struct V_129 ) , V_49 ) ;
if ( ! V_130 )
return - V_18 ;
V_130 -> V_122 = V_122 ;
V_130 -> V_123 = V_123 ;
V_130 -> V_124 = V_124 ;
V_130 -> V_125 = V_125 ;
F_71 ( & V_130 -> V_131 , V_128 , V_3 ) ;
F_72 ( & V_130 -> V_131 , & V_6 -> V_127 ) ;
return 0 ;
}
static struct V_129 * F_73 ( struct V_5 * V_6 , T_3 V_122 )
{
struct V_126 * V_3 = V_6 -> V_127 . V_126 ;
struct V_129 * V_130 ;
while ( V_3 ) {
V_130 = F_70 ( V_3 , struct V_129 , V_131 ) ;
if ( V_122 < V_130 -> V_122 )
V_3 = V_3 -> V_132 ;
else if ( V_122 > V_130 -> V_122 )
V_3 = V_3 -> V_133 ;
else
return V_130 ;
}
return NULL ;
}
static void F_74 ( struct V_5 * V_6 , T_3 V_122 )
{
struct V_129 * V_130 = F_73 ( V_6 , V_122 ) ;
if ( ! V_130 )
return;
F_75 ( & V_130 -> V_131 , & V_6 -> V_127 ) ;
F_22 ( V_130 ) ;
}
void F_76 ( struct V_5 * V_6 )
{
struct V_126 * V_134 = V_6 -> V_127 . V_126 ;
struct V_129 * V_130 ;
while ( V_134 ) {
if ( V_134 -> V_132 ) {
V_134 = V_134 -> V_132 ;
continue;
} else if ( V_134 -> V_133 ) {
V_134 = V_134 -> V_133 ;
continue;
}
V_130 = F_70 ( V_134 , struct V_129 , V_131 ) ;
if ( V_130 -> V_135 )
F_77 ( V_130 -> V_135 ) ;
V_134 = F_78 ( V_134 ) ;
if ( V_134 ) {
if ( V_134 -> V_132 == & V_130 -> V_131 )
V_134 -> V_132 = NULL ;
else
V_134 -> V_133 = NULL ;
}
F_22 ( V_130 ) ;
}
V_6 -> V_127 = V_136 ;
}
int F_79 ( struct V_5 * V_6 , union V_137 * V_138 ,
int V_139 , T_4 V_140 )
{
T_3 V_122 = F_80 ( V_6 , V_138 ) ;
struct V_129 * V_130 ;
int V_14 ;
switch ( F_81 ( V_6 , V_138 ) ) {
case V_141 :
if ( V_139 )
F_74 ( V_6 , V_122 ) ;
else {
V_130 = F_73 ( V_6 , V_122 ) ;
if ( V_130 ) {
V_130 -> V_123 = V_140 ;
V_130 -> V_125 = 1 ;
} else {
V_14 = F_69 ( V_6 , V_122 , V_140 , 0 , 1 ) ;
if ( V_14 )
return V_14 ;
}
}
break;
case V_142 :
V_130 = F_73 ( V_6 , V_122 ) ;
if ( V_130 ) {
if ( V_140 > V_130 -> V_124 )
V_130 -> V_124 = V_140 ;
} else {
V_14 = F_69 ( V_6 , V_122 , 0 , V_140 , 0 ) ;
if ( V_14 )
return V_14 ;
}
break;
case V_143 :
V_130 = F_73 ( V_6 , V_122 ) ;
if ( V_130 )
V_130 -> V_124 = V_140 ;
break;
}
return 0 ;
}
static int F_82 ( struct V_5 * V_6 , struct V_129 * V_130 )
{
struct V_144 * V_145 = V_6 -> V_16 ;
unsigned char * V_3 ;
union V_137 V_138 ;
int V_14 , V_7 , V_15 , V_2 ;
T_4 V_123 ;
T_5 V_146 ;
F_83 ( V_6 , & V_138 , V_130 -> V_122 ) ;
V_14 = F_84 ( V_6 , & V_138 , V_145 , & V_7 , & V_15 ) ;
if ( V_14 )
goto V_36;
V_123 = F_18 ( V_145 -> V_147 ) ;
if ( V_123 >= V_130 -> V_124 )
return 0 ;
V_14 = F_5 ( V_6 , V_7 , V_6 -> V_16 , 0 , V_6 -> V_17 , 1 ) ;
if ( V_14 )
goto V_36;
V_145 = V_6 -> V_16 + V_15 ;
V_145 -> V_147 = F_85 ( V_130 -> V_124 ) ;
V_2 = F_6 ( V_145 -> V_23 . V_2 ) ;
V_146 = F_86 ( V_148 , ( void * ) V_145 + 8 , V_2 - 8 ) ;
V_145 -> V_23 . V_146 = F_12 ( V_146 ) ;
V_3 = V_6 -> V_16 ;
V_2 = V_6 -> V_17 - 1 ;
while ( V_3 [ V_2 ] == 0xff )
V_2 -= 1 ;
V_2 = F_24 ( V_2 + 1 , V_6 -> V_57 ) ;
V_14 = F_14 ( V_6 , V_7 , V_6 -> V_16 , V_2 ) ;
if ( V_14 )
goto V_36;
F_8 ( L_47 ,
( unsigned long ) V_130 -> V_122 , V_7 , V_15 , V_123 , V_130 -> V_124 ) ;
return 0 ;
V_36:
F_87 ( L_48 ,
( unsigned long ) V_130 -> V_122 , V_130 -> V_123 , V_130 -> V_124 , V_14 ) ;
return V_14 ;
}
int F_88 ( struct V_5 * V_6 )
{
struct V_126 * V_134 = F_89 ( & V_6 -> V_127 ) ;
while ( V_134 ) {
struct V_129 * V_130 ;
int V_14 ;
V_130 = F_70 ( V_134 , struct V_129 , V_131 ) ;
if ( ! V_130 -> V_125 ) {
union V_137 V_138 ;
F_83 ( V_6 , & V_138 , V_130 -> V_122 ) ;
V_14 = F_90 ( V_6 , & V_138 , V_6 -> V_16 ) ;
if ( V_14 && V_14 != - V_149 )
return V_14 ;
if ( V_14 == - V_149 ) {
F_8 ( L_49 ,
( unsigned long ) V_130 -> V_122 ) ;
V_14 = F_91 ( V_6 , V_130 -> V_122 ) ;
if ( V_14 )
return V_14 ;
} else {
struct V_144 * V_145 = V_6 -> V_16 ;
V_130 -> V_125 = 1 ;
V_130 -> V_123 = F_18 ( V_145 -> V_147 ) ;
}
}
if ( V_130 -> V_125 && V_130 -> V_123 < V_130 -> V_124 ) {
if ( V_6 -> V_47 ) {
struct V_135 * V_135 ;
struct V_150 * V_151 ;
F_26 ( ! V_130 -> V_135 ) ;
V_135 = F_92 ( V_6 -> V_152 , V_130 -> V_122 ) ;
if ( F_41 ( V_135 ) )
return F_93 ( V_135 ) ;
V_151 = V_150 ( V_135 ) ;
if ( V_135 -> V_123 < V_130 -> V_124 ) {
F_8 ( L_50 ,
( unsigned long ) V_130 -> V_122 ,
V_135 -> V_123 , V_130 -> V_124 ) ;
V_135 -> V_123 = V_130 -> V_124 ;
V_151 -> V_153 = V_130 -> V_124 ;
V_151 -> V_154 = V_130 -> V_124 ;
V_130 -> V_135 = V_135 ;
V_134 = F_94 ( V_134 ) ;
continue;
}
F_77 ( V_135 ) ;
} else {
V_14 = F_82 ( V_6 , V_130 ) ;
if ( V_14 )
return V_14 ;
if ( V_130 -> V_135 )
F_77 ( V_130 -> V_135 ) ;
}
}
V_134 = F_94 ( V_134 ) ;
F_75 ( & V_130 -> V_131 , & V_6 -> V_127 ) ;
F_22 ( V_130 ) ;
}
return 0 ;
}
