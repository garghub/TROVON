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
void F_17 ( struct V_10 * V_10 ,
T_2 V_20 , T_2 V_23 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 = NULL ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
F_15 ( V_16 == NULL ) ;
F_15 ( V_23 < V_20 ) ;
F_18 ( V_10 , V_20 ) ;
F_19 ( & F_8 ( V_10 ) -> V_25 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_26 = 0 ;
if ( V_6 -> V_9 ) {
V_24 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_24 -> V_17 , V_24 -> V_18 ) ) {
F_21 ( L_5 ,
V_20 , V_24 -> V_17 , V_24 -> V_18 ,
F_11 ( V_24 ) , F_12 ( V_24 ) ) ;
goto V_27;
}
}
V_24 = F_16 ( & V_6 -> V_7 , V_20 ) ;
V_27:
if ( V_24 && ! F_22 ( V_24 ) ) {
while ( ( V_12 = F_13 ( & V_24 -> V_11 ) ) != NULL ) {
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_24 -> V_17 > V_23 ) {
V_24 = NULL ;
break;
}
if ( F_22 ( V_24 ) )
break;
}
}
if ( V_24 && F_22 ( V_24 ) ) {
V_6 -> V_9 = V_24 ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_24 ( V_10 , V_16 ) ;
}
static void F_25 ( struct V_10 * V_10 )
{
struct V_28 * V_29 = F_8 ( V_10 ) ;
struct V_30 * V_31 = F_26 ( V_10 -> V_32 ) ;
if ( ! F_27 ( & V_29 -> V_33 ) )
return;
F_28 ( & V_31 -> V_34 ) ;
if ( F_27 ( & V_29 -> V_33 ) ) {
F_29 ( & V_29 -> V_33 , & V_31 -> V_35 ) ;
V_31 -> V_36 ++ ;
}
F_30 ( & V_31 -> V_34 ) ;
}
static void F_31 ( struct V_10 * V_10 )
{
struct V_28 * V_29 = F_8 ( V_10 ) ;
struct V_30 * V_31 = F_26 ( V_10 -> V_32 ) ;
F_28 ( & V_31 -> V_34 ) ;
if ( ! F_27 ( & V_29 -> V_33 ) ) {
F_32 ( & V_29 -> V_33 ) ;
V_31 -> V_36 -- ;
F_33 ( V_31 -> V_36 < 0 ) ;
}
F_30 ( & V_31 -> V_34 ) ;
}
static struct V_2 *
F_34 ( struct V_10 * V_10 , T_2 V_20 , T_2 V_37 ,
T_3 V_38 )
{
struct V_2 * V_16 ;
V_16 = F_35 ( V_1 , V_39 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_17 = V_20 ;
V_16 -> V_18 = V_37 ;
V_16 -> V_26 = V_38 ;
if ( ! F_22 ( V_16 ) ) {
if ( ! F_8 ( V_10 ) -> V_40 ++ )
F_25 ( V_10 ) ;
F_36 ( & F_26 ( V_10 -> V_32 ) ->
V_41 . V_42 ) ;
}
F_8 ( V_10 ) -> V_43 ++ ;
F_36 ( & F_26 ( V_10 -> V_32 ) -> V_41 . V_44 ) ;
return V_16 ;
}
static void F_37 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
F_8 ( V_10 ) -> V_43 -- ;
F_38 ( & F_26 ( V_10 -> V_32 ) -> V_41 . V_44 ) ;
if ( ! F_22 ( V_16 ) ) {
F_15 ( F_8 ( V_10 ) -> V_40 == 0 ) ;
if ( ! -- F_8 ( V_10 ) -> V_40 )
F_31 ( V_10 ) ;
F_38 ( & F_26 ( V_10 -> V_32 ) ->
V_41 . V_42 ) ;
}
F_39 ( V_1 , V_16 ) ;
}
static int F_40 ( struct V_2 * V_24 ,
struct V_2 * V_45 )
{
if ( F_41 ( V_24 ) != F_41 ( V_45 ) )
return 0 ;
if ( ( ( V_46 ) V_24 -> V_18 ) + V_45 -> V_18 > V_47 ) {
F_42 ( L_6
L_7
L_8 ,
V_24 -> V_18 , V_45 -> V_18 , V_47 ) ;
F_43 ( 1 ) ;
return 0 ;
}
if ( ( ( V_46 ) V_24 -> V_17 ) + V_24 -> V_18 != V_45 -> V_17 )
return 0 ;
if ( ( F_44 ( V_24 ) || F_45 ( V_24 ) ) &&
( F_11 ( V_24 ) + V_24 -> V_18 == F_11 ( V_45 ) ) )
return 1 ;
if ( F_46 ( V_24 ) )
return 1 ;
if ( F_22 ( V_24 ) && ! F_45 ( V_24 ) )
return 1 ;
return 0 ;
}
static struct V_2 *
F_47 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_24 ;
struct V_11 * V_12 ;
V_12 = F_48 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_40 ( V_24 , V_16 ) ) {
V_24 -> V_18 += V_16 -> V_18 ;
if ( F_49 ( V_16 ) )
F_50 ( V_24 ) ;
F_51 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_37 ( V_10 , V_16 ) ;
V_16 = V_24 ;
}
return V_16 ;
}
static struct V_2 *
F_52 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_24 ;
struct V_11 * V_12 ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_40 ( V_16 , V_24 ) ) {
V_16 -> V_18 += V_24 -> V_18 ;
if ( F_49 ( V_24 ) )
F_50 ( V_16 ) ;
F_51 ( V_12 , & V_6 -> V_7 ) ;
F_37 ( V_10 , V_24 ) ;
}
return V_16 ;
}
static void F_53 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_48 * V_49 = NULL ;
struct V_50 * V_51 ;
T_2 V_52 ;
T_3 V_53 ;
unsigned short V_54 ;
int V_55 , V_56 , V_57 ;
V_49 = F_54 ( V_10 , V_16 -> V_17 , NULL , V_58 ) ;
if ( F_55 ( V_49 ) )
return;
V_55 = F_56 ( V_10 ) ;
V_51 = V_49 [ V_55 ] . V_59 ;
if ( V_51 ) {
V_52 = F_57 ( V_51 -> V_52 ) ;
V_53 = F_58 ( V_51 ) ;
V_54 = F_59 ( V_51 ) ;
V_56 = F_60 ( V_51 ) ? 1 : 0 ;
V_57 = F_45 ( V_16 ) ? 1 : 0 ;
if ( ! F_44 ( V_16 ) && ! F_45 ( V_16 ) ) {
if ( F_20 ( V_16 -> V_17 , V_52 , V_54 ) ) {
F_42 ( L_9
L_10
L_11
L_12
L_13 ,
V_10 -> V_14 , V_52 , V_54 ,
V_53 , V_56 ? 'u' : 'w' ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
goto V_27;
}
if ( V_16 -> V_17 < V_52 ||
F_11 ( V_16 ) != V_53 + V_16 -> V_17 - V_52 ) {
F_42 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_52 , V_54 , V_53 ,
V_56 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_57 ? 'u' : 'w' ) ;
goto V_27;
}
if ( V_56 ^ V_57 ) {
F_42 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_52 , V_54 , V_53 ,
V_56 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_57 ? 'u' : 'w' ) ;
}
} else {
if ( ! F_22 ( V_16 ) && ! F_46 ( V_16 ) ) {
F_42 ( L_14
L_17
L_18
L_13 , V_10 -> V_14 ,
V_16 -> V_17 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
}
V_27:
F_61 ( V_49 ) ;
F_62 ( V_49 ) ;
}
static void F_63 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_60 V_61 ;
int V_62 ;
V_61 . V_63 = V_16 -> V_17 ;
V_61 . V_64 = V_16 -> V_18 ;
V_62 = F_64 ( NULL , V_10 , & V_61 , 0 ) ;
if ( V_62 > 0 ) {
if ( F_22 ( V_16 ) || F_46 ( V_16 ) ) {
F_42 ( L_14
L_19
L_20 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
} else if ( F_44 ( V_16 ) ) {
if ( V_62 != V_16 -> V_18 ) {
F_42 ( L_9
L_21 ,
V_10 -> V_14 , V_62 , V_16 -> V_18 ) ;
return;
}
if ( V_61 . V_65 != F_11 ( V_16 ) ) {
F_42 ( L_9
L_22
L_23 ,
V_10 -> V_14 , V_61 . V_65 ,
F_11 ( V_16 ) ) ;
return;
}
} else {
F_15 ( 1 ) ;
}
} else if ( V_62 == 0 ) {
if ( F_44 ( V_16 ) ) {
F_42 ( L_14
L_24
L_25 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
}
}
}
static inline void F_65 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
F_15 ( ! F_66 ( & F_8 ( V_10 ) -> V_66 ) ) ;
if ( F_67 ( V_10 , V_67 ) )
F_53 ( V_10 , V_16 ) ;
else
F_63 ( V_10 , V_16 ) ;
}
static inline void F_65 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
}
static int F_68 ( struct V_10 * V_10 , struct V_2 * V_68 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * * V_69 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_70 = NULL ;
struct V_2 * V_16 ;
while ( * V_69 ) {
V_70 = * V_69 ;
V_16 = F_10 ( V_70 , struct V_2 , V_11 ) ;
if ( V_68 -> V_17 < V_16 -> V_17 ) {
if ( F_40 ( V_68 , V_16 ) ) {
V_16 -> V_17 = V_68 -> V_17 ;
V_16 -> V_18 += V_68 -> V_18 ;
if ( F_44 ( V_16 ) ||
F_45 ( V_16 ) )
F_69 ( V_16 ,
V_68 -> V_26 ) ;
V_16 = F_47 ( V_10 , V_16 ) ;
goto V_27;
}
V_69 = & ( * V_69 ) -> V_21 ;
} else if ( V_68 -> V_17 > F_14 ( V_16 ) ) {
if ( F_40 ( V_16 , V_68 ) ) {
V_16 -> V_18 += V_68 -> V_18 ;
V_16 = F_52 ( V_10 , V_16 ) ;
goto V_27;
}
V_69 = & ( * V_69 ) -> V_22 ;
} else {
F_15 ( 1 ) ;
return - V_71 ;
}
}
V_16 = F_34 ( V_10 , V_68 -> V_17 , V_68 -> V_18 ,
V_68 -> V_26 ) ;
if ( ! V_16 )
return - V_4 ;
F_70 ( & V_16 -> V_11 , V_70 , V_69 ) ;
F_71 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_27:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_72 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_37 , T_3 V_38 ,
unsigned int V_72 )
{
struct V_2 V_68 ;
T_2 V_23 = V_20 + V_37 - 1 ;
int V_73 = 0 ;
F_21 ( L_26 ,
V_20 , V_37 , V_38 , V_72 , V_10 -> V_14 ) ;
if ( ! V_37 )
return 0 ;
F_15 ( V_23 < V_20 ) ;
if ( ( V_72 & V_74 ) &&
( V_72 & V_75 ) ) {
F_73 ( V_10 -> V_32 , L_27
L_28
L_29 , V_20 , V_37 ) ;
F_43 ( 1 ) ;
}
V_68 . V_17 = V_20 ;
V_68 . V_18 = V_37 ;
F_74 ( & V_68 , V_38 , V_72 ) ;
F_75 ( V_10 , & V_68 ) ;
F_65 ( V_10 , & V_68 ) ;
F_76 ( & F_8 ( V_10 ) -> V_25 ) ;
V_73 = F_77 ( V_10 , V_20 , V_23 ) ;
if ( V_73 != 0 )
goto error;
V_76:
V_73 = F_68 ( V_10 , & V_68 ) ;
if ( V_73 == - V_4 && F_78 ( F_26 ( V_10 -> V_32 ) ,
128 , F_8 ( V_10 ) ) )
goto V_76;
if ( V_73 == - V_4 && ! F_22 ( & V_68 ) )
V_73 = 0 ;
error:
F_79 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_73 ;
}
void F_80 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_37 , T_3 V_38 ,
unsigned int V_72 )
{
struct V_2 * V_16 ;
struct V_2 V_68 ;
T_2 V_23 = V_20 + V_37 - 1 ;
V_68 . V_17 = V_20 ;
V_68 . V_18 = V_37 ;
F_74 ( & V_68 , V_38 , V_72 ) ;
F_81 ( V_10 , & V_68 ) ;
if ( ! V_37 )
return;
F_15 ( V_23 < V_20 ) ;
F_76 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 = F_16 ( & F_8 ( V_10 ) -> V_15 . V_7 , V_20 ) ;
if ( ! V_16 || V_16 -> V_17 > V_23 )
F_68 ( V_10 , & V_68 ) ;
F_79 ( & F_8 ( V_10 ) -> V_25 ) ;
}
int F_82 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_77 * V_78 ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
int V_79 = 0 ;
F_83 ( V_10 , V_20 ) ;
F_21 ( L_30 , V_20 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
F_19 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_26 = 0 ;
if ( V_6 -> V_9 ) {
V_24 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_24 -> V_17 , V_24 -> V_18 ) ) {
F_21 ( L_31 ,
V_20 , V_24 -> V_17 , V_24 -> V_18 ) ;
V_79 = 1 ;
goto V_27;
}
}
V_12 = V_6 -> V_7 . V_11 ;
while ( V_12 ) {
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( V_20 < V_24 -> V_17 )
V_12 = V_12 -> V_21 ;
else if ( V_20 > F_14 ( V_24 ) )
V_12 = V_12 -> V_22 ;
else {
V_79 = 1 ;
break;
}
}
V_27:
V_78 = & F_26 ( V_10 -> V_32 ) -> V_41 ;
if ( V_79 ) {
F_15 ( ! V_24 ) ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
if ( ! F_49 ( V_16 ) )
F_50 ( V_16 ) ;
V_78 -> V_80 ++ ;
} else {
V_78 -> V_81 ++ ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_84 ( V_10 , V_16 , V_79 ) ;
return V_79 ;
}
static int F_77 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_23 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_82 ;
T_2 V_83 , V_84 ;
T_3 V_85 ;
int V_73 ;
V_76:
V_73 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_23 )
goto V_27;
V_6 -> V_9 = NULL ;
V_82 . V_17 = V_16 -> V_17 ;
V_82 . V_18 = V_16 -> V_18 ;
V_82 . V_26 = V_16 -> V_26 ;
V_83 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_84 = F_14 ( V_16 ) > V_23 ? F_14 ( V_16 ) - V_23 : 0 ;
if ( V_83 > 0 )
V_16 -> V_18 = V_83 ;
if ( V_84 > 0 ) {
if ( V_83 > 0 ) {
struct V_2 V_68 ;
V_68 . V_17 = V_23 + 1 ;
V_68 . V_18 = V_84 ;
V_85 = 0x7FDEADBEEFULL ;
if ( F_44 ( & V_82 ) ||
F_45 ( & V_82 ) )
V_85 = F_11 ( & V_82 ) +
V_82 . V_18 - V_84 ;
F_74 ( & V_68 , V_85 ,
F_12 ( & V_82 ) ) ;
V_73 = F_68 ( V_10 , & V_68 ) ;
if ( V_73 ) {
V_16 -> V_17 = V_82 . V_17 ;
V_16 -> V_18 = V_82 . V_18 ;
if ( ( V_73 == - V_4 ) &&
F_78 ( F_26 ( V_10 -> V_32 ) ,
128 , F_8 ( V_10 ) ) )
goto V_76;
goto V_27;
}
} else {
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_84 ;
if ( F_44 ( V_16 ) ||
F_45 ( V_16 ) ) {
V_85 = V_82 . V_26 + V_82 . V_18 - V_84 ;
F_69 ( V_16 , V_85 ) ;
}
}
goto V_27;
}
if ( V_83 > 0 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( V_12 )
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
else
V_16 = NULL ;
}
while ( V_16 && F_14 ( V_16 ) <= V_23 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
F_51 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_37 ( V_10 , V_16 ) ;
if ( ! V_12 ) {
V_16 = NULL ;
break;
}
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
if ( V_16 && V_16 -> V_17 < V_23 + 1 ) {
T_2 V_86 = V_16 -> V_18 ;
V_83 = F_14 ( V_16 ) - V_23 ;
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_83 ;
if ( F_44 ( V_16 ) || F_45 ( V_16 ) ) {
V_85 = V_16 -> V_26 + V_86 - V_83 ;
F_69 ( V_16 , V_85 ) ;
}
}
V_27:
return V_73 ;
}
int F_85 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_37 )
{
T_2 V_23 ;
int V_73 = 0 ;
F_86 ( V_10 , V_20 , V_37 ) ;
F_21 ( L_32 ,
V_20 , V_37 , V_10 -> V_14 ) ;
if ( ! V_37 )
return V_73 ;
V_23 = V_20 + V_37 - 1 ;
F_15 ( V_23 < V_20 ) ;
F_76 ( & F_8 ( V_10 ) -> V_25 ) ;
V_73 = F_77 ( V_10 , V_20 , V_23 ) ;
F_79 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_73 ;
}
static int F_78 ( struct V_30 * V_31 , int V_87 ,
struct V_28 * V_88 )
{
struct V_28 * V_29 ;
struct V_77 * V_89 ;
T_4 V_90 ;
T_5 V_91 ;
int V_92 ;
int V_93 = 0 ;
int V_94 = 0 , V_95 = 0 ;
V_89 = & V_31 -> V_41 ;
V_90 = F_87 () ;
V_76:
F_28 ( & V_31 -> V_34 ) ;
V_92 = V_31 -> V_36 ;
while ( V_92 -- > 0 ) {
if ( F_27 ( & V_31 -> V_35 ) ) {
F_30 ( & V_31 -> V_34 ) ;
goto V_27;
}
V_29 = F_88 ( & V_31 -> V_35 , struct V_28 ,
V_33 ) ;
F_89 ( & V_29 -> V_33 , & V_31 -> V_35 ) ;
if ( ! V_94 && F_90 ( & V_29 -> V_96 ,
V_97 ) ) {
V_95 ++ ;
continue;
}
if ( V_29 == V_88 || ! F_91 ( & V_29 -> V_25 ) ) {
V_95 ++ ;
continue;
}
F_30 ( & V_31 -> V_34 ) ;
V_93 += F_92 ( V_29 , & V_87 ) ;
F_79 ( & V_29 -> V_25 ) ;
if ( V_87 <= 0 )
goto V_27;
F_28 ( & V_31 -> V_34 ) ;
}
F_30 ( & V_31 -> V_34 ) ;
if ( ( V_93 == 0 ) && V_95 && ! V_94 ) {
V_94 ++ ;
goto V_76;
}
if ( V_88 && V_93 == 0 )
V_93 = F_92 ( V_88 , & V_87 ) ;
V_27:
V_91 = F_93 ( F_94 ( F_87 () , V_90 ) ) ;
if ( F_95 ( V_89 -> V_98 ) )
V_89 -> V_98 = ( V_91 +
V_89 -> V_98 * 3 ) / 4 ;
else
V_89 -> V_98 = V_91 ;
if ( V_91 > V_89 -> V_99 )
V_89 -> V_99 = V_91 ;
if ( F_95 ( V_89 -> V_100 ) )
V_89 -> V_100 = ( V_93 +
V_89 -> V_100 * 3 ) / 4 ;
else
V_89 -> V_100 = V_93 ;
F_96 ( V_31 -> V_101 , V_93 , V_91 ,
V_95 , V_94 ) ;
return V_93 ;
}
static unsigned long F_97 ( struct V_102 * V_103 ,
struct V_104 * V_105 )
{
unsigned long V_106 ;
struct V_30 * V_31 ;
V_31 = F_98 ( V_103 , struct V_30 , V_107 ) ;
V_106 = F_99 ( & V_31 -> V_41 . V_42 ) ;
F_100 ( V_31 -> V_101 , V_105 -> V_87 , V_106 ) ;
return V_106 ;
}
static unsigned long F_101 ( struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_30 * V_31 = F_98 ( V_103 ,
struct V_30 , V_107 ) ;
int V_87 = V_105 -> V_87 ;
int V_108 , V_93 ;
V_108 = F_99 ( & V_31 -> V_41 . V_42 ) ;
F_102 ( V_31 -> V_101 , V_87 , V_108 ) ;
if ( ! V_87 )
return V_108 ;
V_93 = F_78 ( V_31 , V_87 , NULL ) ;
F_103 ( V_31 -> V_101 , V_93 , V_108 ) ;
return V_93 ;
}
static void * F_104 ( struct V_109 * V_110 , T_6 * V_111 )
{
return * V_111 ? NULL : V_112 ;
}
static void *
F_105 ( struct V_109 * V_110 , void * V_113 , T_6 * V_111 )
{
return NULL ;
}
static int F_106 ( struct V_109 * V_110 , void * V_113 )
{
struct V_30 * V_31 = V_110 -> V_114 ;
struct V_77 * V_89 = & V_31 -> V_41 ;
struct V_28 * V_29 , * V_115 = NULL ;
unsigned int V_116 = 0 ;
if ( V_113 != V_112 )
return 0 ;
F_28 ( & V_31 -> V_34 ) ;
F_107 (ei, &sbi->s_es_list, i_es_list) {
V_116 ++ ;
if ( V_115 && V_115 -> V_43 < V_29 -> V_43 )
V_115 = V_29 ;
else if ( ! V_115 )
V_115 = V_29 ;
}
F_30 ( & V_31 -> V_34 ) ;
F_108 ( V_110 , L_33 ,
F_109 ( & V_89 -> V_44 ) ,
F_109 ( & V_89 -> V_42 ) ) ;
F_108 ( V_110 , L_34 ,
V_89 -> V_80 ,
V_89 -> V_81 ) ;
if ( V_116 )
F_108 ( V_110 , L_35 , V_116 ) ;
F_108 ( V_110 , L_36 ,
F_110 ( V_89 -> V_98 , 1000 ) ) ;
F_108 ( V_110 , L_37 , V_89 -> V_100 ) ;
if ( V_116 )
F_108 ( V_110 ,
L_38
L_39 ,
V_115 -> V_96 . V_14 , V_115 -> V_43 , V_115 -> V_40 ,
F_110 ( V_89 -> V_99 , 1000 ) ) ;
return 0 ;
}
static void F_111 ( struct V_109 * V_110 , void * V_113 )
{
}
static int
F_112 ( struct V_10 * V_10 , struct V_117 * V_117 )
{
int V_108 ;
V_108 = F_113 ( V_117 , & V_118 ) ;
if ( ! V_108 ) {
struct V_109 * V_119 = V_117 -> V_120 ;
V_119 -> V_114 = F_114 ( V_10 ) ;
}
return V_108 ;
}
static int
F_115 ( struct V_10 * V_10 , struct V_117 * V_117 )
{
return F_116 ( V_10 , V_117 ) ;
}
int F_117 ( struct V_30 * V_31 )
{
int V_73 ;
F_118 ( V_121 < 48 ) ;
F_119 ( & V_31 -> V_35 ) ;
V_31 -> V_36 = 0 ;
F_120 ( & V_31 -> V_34 ) ;
V_31 -> V_41 . V_100 = 0 ;
V_31 -> V_41 . V_80 = 0 ;
V_31 -> V_41 . V_81 = 0 ;
V_31 -> V_41 . V_98 = 0 ;
V_31 -> V_41 . V_99 = 0 ;
V_73 = F_121 ( & V_31 -> V_41 . V_44 , 0 , V_122 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_121 ( & V_31 -> V_41 . V_42 , 0 , V_122 ) ;
if ( V_73 )
goto V_123;
V_31 -> V_107 . V_124 = F_101 ;
V_31 -> V_107 . V_125 = F_97 ;
V_31 -> V_107 . V_126 = V_127 ;
V_73 = F_122 ( & V_31 -> V_107 ) ;
if ( V_73 )
goto V_128;
if ( V_31 -> V_129 )
F_123 ( L_40 , V_130 , V_31 -> V_129 ,
& V_131 , V_31 ) ;
return 0 ;
V_128:
F_124 ( & V_31 -> V_41 . V_42 ) ;
V_123:
F_124 ( & V_31 -> V_41 . V_44 ) ;
return V_73 ;
}
void F_125 ( struct V_30 * V_31 )
{
if ( V_31 -> V_129 )
F_126 ( L_40 , V_31 -> V_129 ) ;
F_124 ( & V_31 -> V_41 . V_44 ) ;
F_124 ( & V_31 -> V_41 . V_42 ) ;
F_127 ( & V_31 -> V_107 ) ;
}
static int F_128 ( struct V_28 * V_29 , T_2 V_23 ,
int * V_87 , int * V_93 )
{
struct V_10 * V_10 = & V_29 -> V_96 ;
struct V_5 * V_6 = & V_29 -> V_15 ;
struct V_2 * V_16 ;
struct V_11 * V_12 ;
V_16 = F_16 ( & V_6 -> V_7 , V_29 -> V_132 ) ;
if ( ! V_16 )
goto V_133;
V_12 = & V_16 -> V_11 ;
while ( * V_87 > 0 ) {
if ( V_16 -> V_17 > V_23 ) {
V_29 -> V_132 = V_23 + 1 ;
return 0 ;
}
( * V_87 ) -- ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( F_22 ( V_16 ) )
goto V_134;
if ( F_49 ( V_16 ) ) {
F_129 ( V_16 ) ;
goto V_134;
}
F_51 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_37 ( V_10 , V_16 ) ;
( * V_93 ) ++ ;
V_134:
if ( ! V_12 )
goto V_133;
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
V_29 -> V_132 = V_16 -> V_17 ;
return 1 ;
V_133:
V_29 -> V_132 = 0 ;
return 0 ;
}
static int F_92 ( struct V_28 * V_29 , int * V_87 )
{
struct V_10 * V_10 = & V_29 -> V_96 ;
int V_93 = 0 ;
T_2 V_135 = V_29 -> V_132 ;
static F_130 ( V_136 , V_137 ,
V_138 ) ;
if ( V_29 -> V_40 == 0 )
return 0 ;
if ( F_90 ( V_10 , V_97 ) &&
F_131 ( & V_136 ) )
F_73 ( V_10 -> V_32 , L_41 ) ;
if ( ! F_128 ( V_29 , V_47 , V_87 , & V_93 ) &&
V_135 != 0 )
F_128 ( V_29 , V_135 - 1 , V_87 , & V_93 ) ;
V_29 -> V_15 . V_9 = NULL ;
return V_93 ;
}
