int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 , ( V_3 ) , NULL ) ;
if ( V_1 == NULL )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
if ( V_1 )
F_4 ( V_1 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
V_6 -> V_7 = V_8 ;
V_6 -> V_9 = NULL ;
}
static void F_6 ( struct V_10 * V_10 )
{
struct V_5 * V_6 ;
struct V_11 * V_12 ;
F_7 ( V_13 L_2 , V_10 -> V_14 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 ) {
struct V_2 * V_16 ;
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
F_7 ( V_13 L_3 ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
V_12 = F_13 ( V_12 ) ;
}
F_7 ( V_13 L_4 ) ;
}
static inline T_2 F_14 ( struct V_2 * V_16 )
{
F_15 ( V_16 -> V_17 + V_16 -> V_18 < V_16 -> V_17 ) ;
return V_16 -> V_17 + V_16 -> V_18 - 1 ;
}
static struct V_2 * F_16 ( struct V_19 * V_7 ,
T_2 V_20 )
{
struct V_11 * V_12 = V_7 -> V_11 ;
struct V_2 * V_16 = NULL ;
while ( V_12 ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_20 < V_16 -> V_17 )
V_12 = V_12 -> V_21 ;
else if ( V_20 > F_14 ( V_16 ) )
V_12 = V_12 -> V_22 ;
else
return V_16 ;
}
if ( V_16 && V_20 < V_16 -> V_17 )
return V_16 ;
if ( V_16 && V_20 > F_14 ( V_16 ) ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
return V_12 ? F_10 ( V_12 , struct V_2 , V_11 ) :
NULL ;
}
return NULL ;
}
void F_17 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_2 * V_23 = NULL ;
struct V_11 * V_12 ;
F_15 ( V_16 == NULL ) ;
F_18 ( V_10 , V_20 ) ;
F_19 ( & F_8 ( V_10 ) -> V_24 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_25 = 0 ;
if ( V_6 -> V_9 ) {
V_23 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_23 -> V_17 , V_23 -> V_18 ) ) {
F_21 ( L_5 ,
V_20 , V_23 -> V_17 , V_23 -> V_18 ,
F_11 ( V_23 ) , F_12 ( V_23 ) ) ;
goto V_26;
}
}
V_23 = F_16 ( & V_6 -> V_7 , V_20 ) ;
V_26:
if ( V_23 && ! F_22 ( V_23 ) ) {
while ( ( V_12 = F_13 ( & V_23 -> V_11 ) ) != NULL ) {
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_22 ( V_23 ) )
break;
}
}
if ( V_23 && F_22 ( V_23 ) ) {
V_6 -> V_9 = V_23 ;
V_16 -> V_17 = V_23 -> V_17 ;
V_16 -> V_18 = V_23 -> V_18 ;
V_16 -> V_25 = V_23 -> V_25 ;
}
F_23 ( & F_8 ( V_10 ) -> V_24 ) ;
F_24 ( V_10 ) ;
F_25 ( V_10 , V_16 ) ;
}
static struct V_2 *
F_26 ( struct V_10 * V_10 , T_2 V_20 , T_2 V_27 ,
T_3 V_28 )
{
struct V_2 * V_16 ;
V_16 = F_27 ( V_1 , V_29 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_17 = V_20 ;
V_16 -> V_18 = V_27 ;
V_16 -> V_25 = V_28 ;
if ( ! F_22 ( V_16 ) ) {
F_8 ( V_10 ) -> V_30 ++ ;
F_28 ( & F_29 ( V_10 -> V_31 ) -> V_32 ) ;
}
return V_16 ;
}
static void F_30 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
if ( ! F_22 ( V_16 ) ) {
F_15 ( F_8 ( V_10 ) -> V_30 == 0 ) ;
F_8 ( V_10 ) -> V_30 -- ;
F_31 ( & F_29 ( V_10 -> V_31 ) -> V_32 ) ;
}
F_32 ( V_1 , V_16 ) ;
}
static int F_33 ( struct V_2 * V_23 ,
struct V_2 * V_33 )
{
if ( F_12 ( V_23 ) != F_12 ( V_33 ) )
return 0 ;
if ( ( ( V_34 ) V_23 -> V_18 ) + V_33 -> V_18 > 0xFFFFFFFFULL )
return 0 ;
if ( ( ( V_34 ) V_23 -> V_17 ) + V_23 -> V_18 != V_33 -> V_17 )
return 0 ;
if ( ( F_34 ( V_23 ) || F_35 ( V_23 ) ) &&
( F_11 ( V_23 ) + V_23 -> V_18 == F_11 ( V_33 ) ) )
return 1 ;
if ( F_36 ( V_23 ) )
return 1 ;
if ( F_22 ( V_23 ) && ! F_35 ( V_23 ) )
return 1 ;
return 0 ;
}
static struct V_2 *
F_37 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_38 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_33 ( V_23 , V_16 ) ) {
V_23 -> V_18 += V_16 -> V_18 ;
F_39 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_30 ( V_10 , V_16 ) ;
V_16 = V_23 ;
}
return V_16 ;
}
static struct V_2 *
F_40 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_33 ( V_16 , V_23 ) ) {
V_16 -> V_18 += V_23 -> V_18 ;
F_39 ( V_12 , & V_6 -> V_7 ) ;
F_30 ( V_10 , V_23 ) ;
}
return V_16 ;
}
static void F_41 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_35 * V_36 = NULL ;
struct V_37 * V_38 ;
T_2 V_39 ;
T_3 V_40 ;
unsigned short V_41 ;
int V_42 , V_43 , V_44 ;
V_36 = F_42 ( V_10 , V_16 -> V_17 , NULL ) ;
if ( F_43 ( V_36 ) )
return;
V_42 = F_44 ( V_10 ) ;
V_38 = V_36 [ V_42 ] . V_45 ;
if ( V_38 ) {
V_39 = F_45 ( V_38 -> V_39 ) ;
V_40 = F_46 ( V_38 ) ;
V_41 = F_47 ( V_38 ) ;
V_43 = F_48 ( V_38 ) ? 1 : 0 ;
V_44 = F_35 ( V_16 ) ? 1 : 0 ;
if ( ! F_34 ( V_16 ) && ! F_35 ( V_16 ) ) {
if ( F_20 ( V_16 -> V_17 , V_39 , V_41 ) ) {
F_49 ( L_6
L_7
L_8
L_9
L_10 ,
V_10 -> V_14 , V_39 , V_41 ,
V_40 , V_43 ? 'u' : 'w' ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
goto V_26;
}
if ( V_16 -> V_17 < V_39 ||
F_11 ( V_16 ) != V_40 + V_16 -> V_17 - V_39 ) {
F_49 ( L_11
L_12
L_13 , V_10 -> V_14 ,
V_39 , V_41 , V_40 ,
V_43 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_44 ? 'u' : 'w' ) ;
goto V_26;
}
if ( V_43 ^ V_44 ) {
F_49 ( L_11
L_12
L_13 , V_10 -> V_14 ,
V_39 , V_41 , V_40 ,
V_43 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_44 ? 'u' : 'w' ) ;
}
} else {
if ( ! F_22 ( V_16 ) && ! F_36 ( V_16 ) ) {
F_49 ( L_11
L_14
L_15
L_10 , V_10 -> V_14 ,
V_16 -> V_17 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
}
V_26:
if ( V_36 ) {
F_50 ( V_36 ) ;
F_51 ( V_36 ) ;
}
}
static void F_52 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_46 V_47 ;
int V_48 ;
V_47 . V_49 = V_16 -> V_17 ;
V_47 . V_50 = V_16 -> V_18 ;
V_48 = F_53 ( NULL , V_10 , & V_47 , 0 ) ;
if ( V_48 > 0 ) {
if ( F_22 ( V_16 ) || F_36 ( V_16 ) ) {
F_49 ( L_11
L_16
L_17 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
} else if ( F_34 ( V_16 ) ) {
if ( V_48 != V_16 -> V_18 ) {
F_49 ( L_6
L_18 ,
V_10 -> V_14 , V_48 , V_16 -> V_18 ) ;
return;
}
if ( V_47 . V_51 != F_11 ( V_16 ) ) {
F_49 ( L_6
L_19
L_20 ,
V_10 -> V_14 , V_47 . V_51 ,
F_11 ( V_16 ) ) ;
return;
}
} else {
F_15 ( 1 ) ;
}
} else if ( V_48 == 0 ) {
if ( F_34 ( V_16 ) ) {
F_49 ( L_11
L_21
L_22 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
}
}
}
static inline void F_54 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
F_15 ( ! F_55 ( & F_8 ( V_10 ) -> V_52 ) ) ;
if ( F_56 ( V_10 , V_53 ) )
F_41 ( V_10 , V_16 ) ;
else
F_52 ( V_10 , V_16 ) ;
}
static inline void F_54 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
}
static int F_57 ( struct V_10 * V_10 , struct V_2 * V_54 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * * V_55 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_56 = NULL ;
struct V_2 * V_16 ;
while ( * V_55 ) {
V_56 = * V_55 ;
V_16 = F_10 ( V_56 , struct V_2 , V_11 ) ;
if ( V_54 -> V_17 < V_16 -> V_17 ) {
if ( F_33 ( V_54 , V_16 ) ) {
V_16 -> V_17 = V_54 -> V_17 ;
V_16 -> V_18 += V_54 -> V_18 ;
if ( F_34 ( V_16 ) ||
F_35 ( V_16 ) )
F_58 ( V_16 ,
V_54 -> V_25 ) ;
V_16 = F_37 ( V_10 , V_16 ) ;
goto V_26;
}
V_55 = & ( * V_55 ) -> V_21 ;
} else if ( V_54 -> V_17 > F_14 ( V_16 ) ) {
if ( F_33 ( V_16 , V_54 ) ) {
V_16 -> V_18 += V_54 -> V_18 ;
V_16 = F_40 ( V_10 , V_16 ) ;
goto V_26;
}
V_55 = & ( * V_55 ) -> V_22 ;
} else {
F_15 ( 1 ) ;
return - V_57 ;
}
}
V_16 = F_26 ( V_10 , V_54 -> V_17 , V_54 -> V_18 ,
V_54 -> V_25 ) ;
if ( ! V_16 )
return - V_4 ;
F_59 ( & V_16 -> V_11 , V_56 , V_55 ) ;
F_60 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_26:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_61 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_27 , T_3 V_28 ,
unsigned long long V_58 )
{
struct V_2 V_54 ;
T_2 V_59 = V_20 + V_27 - 1 ;
int V_60 = 0 ;
F_21 ( L_23 ,
V_20 , V_27 , V_28 , V_58 , V_10 -> V_14 ) ;
if ( ! V_27 )
return 0 ;
F_15 ( V_59 < V_20 ) ;
V_54 . V_17 = V_20 ;
V_54 . V_18 = V_27 ;
F_58 ( & V_54 , V_28 ) ;
F_62 ( & V_54 , V_58 ) ;
F_63 ( V_10 , & V_54 ) ;
F_54 ( V_10 , & V_54 ) ;
F_64 ( & F_8 ( V_10 ) -> V_24 ) ;
V_60 = F_65 ( V_10 , V_20 , V_59 ) ;
if ( V_60 != 0 )
goto error;
V_60 = F_57 ( V_10 , & V_54 ) ;
error:
F_66 ( & F_8 ( V_10 ) -> V_24 ) ;
F_24 ( V_10 ) ;
F_6 ( V_10 ) ;
return V_60 ;
}
int F_67 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_2 * V_23 = NULL ;
struct V_11 * V_12 ;
int V_61 = 0 ;
F_68 ( V_10 , V_20 ) ;
F_21 ( L_24 , V_20 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
F_19 ( & F_8 ( V_10 ) -> V_24 ) ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_25 = 0 ;
if ( V_6 -> V_9 ) {
V_23 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_23 -> V_17 , V_23 -> V_18 ) ) {
F_21 ( L_25 ,
V_20 , V_23 -> V_17 , V_23 -> V_18 ) ;
V_61 = 1 ;
goto V_26;
}
}
V_12 = V_6 -> V_7 . V_11 ;
while ( V_12 ) {
V_23 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_20 < V_23 -> V_17 )
V_12 = V_12 -> V_21 ;
else if ( V_20 > F_14 ( V_23 ) )
V_12 = V_12 -> V_22 ;
else {
V_61 = 1 ;
break;
}
}
V_26:
if ( V_61 ) {
F_15 ( ! V_23 ) ;
V_16 -> V_17 = V_23 -> V_17 ;
V_16 -> V_18 = V_23 -> V_18 ;
V_16 -> V_25 = V_23 -> V_25 ;
}
F_23 ( & F_8 ( V_10 ) -> V_24 ) ;
F_24 ( V_10 ) ;
F_69 ( V_10 , V_16 , V_61 ) ;
return V_61 ;
}
static int F_65 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_59 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_62 ;
T_2 V_63 , V_64 ;
T_3 V_65 ;
int V_60 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_26;
if ( V_16 -> V_17 > V_59 )
goto V_26;
V_6 -> V_9 = NULL ;
V_62 . V_17 = V_16 -> V_17 ;
V_62 . V_18 = V_16 -> V_18 ;
V_62 . V_25 = V_16 -> V_25 ;
V_63 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_64 = F_14 ( V_16 ) > V_59 ? F_14 ( V_16 ) - V_59 : 0 ;
if ( V_63 > 0 )
V_16 -> V_18 = V_63 ;
if ( V_64 > 0 ) {
if ( V_63 > 0 ) {
struct V_2 V_54 ;
V_54 . V_17 = V_59 + 1 ;
V_54 . V_18 = V_64 ;
if ( F_34 ( & V_62 ) ||
F_35 ( & V_62 ) ) {
V_65 = F_11 ( & V_62 ) +
V_62 . V_18 - V_64 ;
F_58 ( & V_54 , V_65 ) ;
}
F_62 ( & V_54 , F_12 ( & V_62 ) ) ;
V_60 = F_57 ( V_10 , & V_54 ) ;
if ( V_60 ) {
V_16 -> V_17 = V_62 . V_17 ;
V_16 -> V_18 = V_62 . V_18 ;
goto V_26;
}
} else {
V_16 -> V_17 = V_59 + 1 ;
V_16 -> V_18 = V_64 ;
if ( F_34 ( V_16 ) ||
F_35 ( V_16 ) ) {
V_65 = V_62 . V_25 + V_62 . V_18 - V_64 ;
F_58 ( V_16 , V_65 ) ;
}
}
goto V_26;
}
if ( V_63 > 0 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( V_12 )
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
else
V_16 = NULL ;
}
while ( V_16 && F_14 ( V_16 ) <= V_59 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
F_39 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_30 ( V_10 , V_16 ) ;
if ( ! V_12 ) {
V_16 = NULL ;
break;
}
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
if ( V_16 && V_16 -> V_17 < V_59 + 1 ) {
T_2 V_66 = V_16 -> V_18 ;
V_63 = F_14 ( V_16 ) - V_59 ;
V_16 -> V_17 = V_59 + 1 ;
V_16 -> V_18 = V_63 ;
if ( F_34 ( V_16 ) || F_35 ( V_16 ) ) {
V_65 = V_16 -> V_25 + V_66 - V_63 ;
F_58 ( V_16 , V_65 ) ;
}
}
V_26:
return V_60 ;
}
int F_70 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_27 )
{
T_2 V_59 ;
int V_60 = 0 ;
F_71 ( V_10 , V_20 , V_27 ) ;
F_21 ( L_26 ,
V_20 , V_27 , V_10 -> V_14 ) ;
if ( ! V_27 )
return V_60 ;
V_59 = V_20 + V_27 - 1 ;
F_15 ( V_59 < V_20 ) ;
F_64 ( & F_8 ( V_10 ) -> V_24 ) ;
V_60 = F_65 ( V_10 , V_20 , V_59 ) ;
F_66 ( & F_8 ( V_10 ) -> V_24 ) ;
F_6 ( V_10 ) ;
return V_60 ;
}
int F_72 ( struct V_10 * V_10 , struct V_37 * V_38 )
{
T_2 V_39 ;
T_3 V_67 ;
unsigned int V_41 ;
V_39 = F_45 ( V_38 -> V_39 ) ;
V_41 = F_47 ( V_38 ) ;
V_67 = F_46 ( V_38 ) ;
if ( V_41 == 0 )
return 0 ;
return F_61 ( V_10 , V_39 , V_41 , V_67 ,
V_68 ) ;
}
static int F_73 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_73 * V_74 = F_74 ( V_70 ,
struct V_73 , V_75 ) ;
struct V_76 * V_77 ;
struct V_78 * V_79 , * V_80 , V_81 ;
int V_82 = V_72 -> V_82 ;
int V_83 , V_84 = 0 ;
V_83 = F_75 ( & V_74 -> V_32 ) ;
F_76 ( V_74 -> V_85 , V_82 , V_83 ) ;
if ( ! V_82 )
return V_83 ;
F_77 ( & V_81 ) ;
F_78 ( & V_74 -> V_86 ) ;
F_79 (cur, tmp, &sbi->s_es_lru) {
F_80 ( V_79 , & V_81 ) ;
V_77 = F_81 ( V_79 , struct V_76 , V_87 ) ;
F_19 ( & V_77 -> V_24 ) ;
if ( V_77 -> V_30 == 0 ) {
F_23 ( & V_77 -> V_24 ) ;
continue;
}
F_23 ( & V_77 -> V_24 ) ;
F_64 ( & V_77 -> V_24 ) ;
V_83 = F_82 ( V_77 , V_82 ) ;
F_66 ( & V_77 -> V_24 ) ;
V_84 += V_83 ;
V_82 -= V_83 ;
if ( V_82 == 0 )
break;
}
F_83 ( & V_81 , & V_74 -> V_88 ) ;
F_84 ( & V_74 -> V_86 ) ;
V_83 = F_75 ( & V_74 -> V_32 ) ;
F_85 ( V_74 -> V_85 , V_84 , V_83 ) ;
return V_83 ;
}
void F_86 ( struct V_89 * V_90 )
{
struct V_73 * V_74 ;
V_74 = F_29 ( V_90 ) ;
F_77 ( & V_74 -> V_88 ) ;
F_87 ( & V_74 -> V_86 ) ;
V_74 -> V_75 . V_70 = F_73 ;
V_74 -> V_75 . V_91 = V_92 ;
F_88 ( & V_74 -> V_75 ) ;
}
void F_89 ( struct V_89 * V_90 )
{
F_90 ( & F_29 ( V_90 ) -> V_75 ) ;
}
void F_24 ( struct V_10 * V_10 )
{
struct V_76 * V_77 = F_8 ( V_10 ) ;
struct V_73 * V_74 = F_29 ( V_10 -> V_31 ) ;
F_78 ( & V_74 -> V_86 ) ;
if ( F_91 ( & V_77 -> V_87 ) )
F_92 ( & V_77 -> V_87 , & V_74 -> V_88 ) ;
else
F_80 ( & V_77 -> V_87 , & V_74 -> V_88 ) ;
F_84 ( & V_74 -> V_86 ) ;
}
void F_93 ( struct V_10 * V_10 )
{
struct V_76 * V_77 = F_8 ( V_10 ) ;
struct V_73 * V_74 = F_29 ( V_10 -> V_31 ) ;
F_78 ( & V_74 -> V_86 ) ;
if ( ! F_91 ( & V_77 -> V_87 ) )
F_94 ( & V_77 -> V_87 ) ;
F_84 ( & V_74 -> V_86 ) ;
}
static int F_82 ( struct V_76 * V_77 ,
int V_82 )
{
struct V_10 * V_10 = & V_77 -> V_93 ;
struct V_5 * V_6 = & V_77 -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
int V_84 = 0 ;
if ( V_77 -> V_30 == 0 )
return 0 ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 != NULL ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! F_22 ( V_16 ) ) {
F_39 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_30 ( V_10 , V_16 ) ;
V_84 ++ ;
if ( -- V_82 == 0 )
break;
}
}
V_6 -> V_9 = NULL ;
return V_84 ;
}
