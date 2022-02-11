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
V_68 . V_17 = V_20 ;
V_68 . V_18 = V_37 ;
F_73 ( & V_68 , V_38 , V_72 ) ;
F_74 ( V_10 , & V_68 ) ;
F_65 ( V_10 , & V_68 ) ;
F_75 ( & F_8 ( V_10 ) -> V_25 ) ;
V_73 = F_76 ( V_10 , V_20 , V_23 ) ;
if ( V_73 != 0 )
goto error;
V_74:
V_73 = F_68 ( V_10 , & V_68 ) ;
if ( V_73 == - V_4 && F_77 ( F_26 ( V_10 -> V_32 ) ,
128 , F_8 ( V_10 ) ) )
goto V_74;
if ( V_73 == - V_4 && ! F_22 ( & V_68 ) )
V_73 = 0 ;
error:
F_78 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_73 ;
}
void F_79 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_37 , T_3 V_38 ,
unsigned int V_72 )
{
struct V_2 * V_16 ;
struct V_2 V_68 ;
T_2 V_23 = V_20 + V_37 - 1 ;
V_68 . V_17 = V_20 ;
V_68 . V_18 = V_37 ;
F_73 ( & V_68 , V_38 , V_72 ) ;
F_80 ( V_10 , & V_68 ) ;
if ( ! V_37 )
return;
F_15 ( V_23 < V_20 ) ;
F_75 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 = F_16 ( & F_8 ( V_10 ) -> V_15 . V_7 , V_20 ) ;
if ( ! V_16 || V_16 -> V_17 > V_23 )
F_68 ( V_10 , & V_68 ) ;
F_78 ( & F_8 ( V_10 ) -> V_25 ) ;
}
int F_81 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_75 * V_76 ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
int V_77 = 0 ;
F_82 ( V_10 , V_20 ) ;
F_21 ( L_27 , V_20 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
F_19 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_26 = 0 ;
if ( V_6 -> V_9 ) {
V_24 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_24 -> V_17 , V_24 -> V_18 ) ) {
F_21 ( L_28 ,
V_20 , V_24 -> V_17 , V_24 -> V_18 ) ;
V_77 = 1 ;
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
V_77 = 1 ;
break;
}
}
V_27:
V_76 = & F_26 ( V_10 -> V_32 ) -> V_41 ;
if ( V_77 ) {
F_15 ( ! V_24 ) ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
if ( ! F_49 ( V_16 ) )
F_50 ( V_16 ) ;
V_76 -> V_78 ++ ;
} else {
V_76 -> V_79 ++ ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_83 ( V_10 , V_16 , V_77 ) ;
return V_77 ;
}
static int F_76 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_23 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_80 ;
T_2 V_81 , V_82 ;
T_3 V_83 ;
int V_73 ;
V_74:
V_73 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_23 )
goto V_27;
V_6 -> V_9 = NULL ;
V_80 . V_17 = V_16 -> V_17 ;
V_80 . V_18 = V_16 -> V_18 ;
V_80 . V_26 = V_16 -> V_26 ;
V_81 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_82 = F_14 ( V_16 ) > V_23 ? F_14 ( V_16 ) - V_23 : 0 ;
if ( V_81 > 0 )
V_16 -> V_18 = V_81 ;
if ( V_82 > 0 ) {
if ( V_81 > 0 ) {
struct V_2 V_68 ;
V_68 . V_17 = V_23 + 1 ;
V_68 . V_18 = V_82 ;
V_83 = 0x7FDEADBEEFULL ;
if ( F_44 ( & V_80 ) ||
F_45 ( & V_80 ) )
V_83 = F_11 ( & V_80 ) +
V_80 . V_18 - V_82 ;
F_73 ( & V_68 , V_83 ,
F_12 ( & V_80 ) ) ;
V_73 = F_68 ( V_10 , & V_68 ) ;
if ( V_73 ) {
V_16 -> V_17 = V_80 . V_17 ;
V_16 -> V_18 = V_80 . V_18 ;
if ( ( V_73 == - V_4 ) &&
F_77 ( F_26 ( V_10 -> V_32 ) ,
128 , F_8 ( V_10 ) ) )
goto V_74;
goto V_27;
}
} else {
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_82 ;
if ( F_44 ( V_16 ) ||
F_45 ( V_16 ) ) {
V_83 = V_80 . V_26 + V_80 . V_18 - V_82 ;
F_69 ( V_16 , V_83 ) ;
}
}
goto V_27;
}
if ( V_81 > 0 ) {
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
T_2 V_84 = V_16 -> V_18 ;
V_81 = F_14 ( V_16 ) - V_23 ;
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_81 ;
if ( F_44 ( V_16 ) || F_45 ( V_16 ) ) {
V_83 = V_16 -> V_26 + V_84 - V_81 ;
F_69 ( V_16 , V_83 ) ;
}
}
V_27:
return V_73 ;
}
int F_84 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_37 )
{
T_2 V_23 ;
int V_73 = 0 ;
F_85 ( V_10 , V_20 , V_37 ) ;
F_21 ( L_29 ,
V_20 , V_37 , V_10 -> V_14 ) ;
if ( ! V_37 )
return V_73 ;
V_23 = V_20 + V_37 - 1 ;
F_15 ( V_23 < V_20 ) ;
F_75 ( & F_8 ( V_10 ) -> V_25 ) ;
V_73 = F_76 ( V_10 , V_20 , V_23 ) ;
F_78 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_73 ;
}
static int F_77 ( struct V_30 * V_31 , int V_85 ,
struct V_28 * V_86 )
{
struct V_28 * V_29 ;
struct V_75 * V_87 ;
T_4 V_88 ;
T_5 V_89 ;
int V_90 ;
int V_91 = 0 ;
int V_92 = 0 , V_93 = 0 ;
V_87 = & V_31 -> V_41 ;
V_88 = F_86 () ;
V_74:
F_28 ( & V_31 -> V_34 ) ;
V_90 = V_31 -> V_36 ;
while ( V_90 -- > 0 ) {
if ( F_27 ( & V_31 -> V_35 ) ) {
F_30 ( & V_31 -> V_34 ) ;
goto V_27;
}
V_29 = F_87 ( & V_31 -> V_35 , struct V_28 ,
V_33 ) ;
F_88 ( & V_29 -> V_33 , & V_31 -> V_35 ) ;
if ( ! V_92 && F_89 ( & V_29 -> V_94 ,
V_95 ) ) {
V_93 ++ ;
continue;
}
if ( V_29 == V_86 || ! F_90 ( & V_29 -> V_25 ) ) {
V_93 ++ ;
continue;
}
F_30 ( & V_31 -> V_34 ) ;
V_91 += F_91 ( V_29 , & V_85 ) ;
F_78 ( & V_29 -> V_25 ) ;
if ( V_85 <= 0 )
goto V_27;
F_28 ( & V_31 -> V_34 ) ;
}
F_30 ( & V_31 -> V_34 ) ;
if ( ( V_91 == 0 ) && V_93 && ! V_92 ) {
V_92 ++ ;
goto V_74;
}
if ( V_86 && V_91 == 0 )
V_91 = F_91 ( V_86 , & V_85 ) ;
V_27:
V_89 = F_92 ( F_93 ( F_86 () , V_88 ) ) ;
if ( F_94 ( V_87 -> V_96 ) )
V_87 -> V_96 = ( V_89 +
V_87 -> V_96 * 3 ) / 4 ;
else
V_87 -> V_96 = V_89 ;
if ( V_89 > V_87 -> V_97 )
V_87 -> V_97 = V_89 ;
if ( F_94 ( V_87 -> V_98 ) )
V_87 -> V_98 = ( V_91 +
V_87 -> V_98 * 3 ) / 4 ;
else
V_87 -> V_98 = V_91 ;
F_95 ( V_31 -> V_99 , V_91 , V_89 ,
V_93 , V_92 ) ;
return V_91 ;
}
static unsigned long F_96 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
unsigned long V_104 ;
struct V_30 * V_31 ;
V_31 = F_97 ( V_101 , struct V_30 , V_105 ) ;
V_104 = F_98 ( & V_31 -> V_41 . V_42 ) ;
F_99 ( V_31 -> V_99 , V_103 -> V_85 , V_104 ) ;
return V_104 ;
}
static unsigned long F_100 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_30 * V_31 = F_97 ( V_101 ,
struct V_30 , V_105 ) ;
int V_85 = V_103 -> V_85 ;
int V_106 , V_91 ;
V_106 = F_98 ( & V_31 -> V_41 . V_42 ) ;
F_101 ( V_31 -> V_99 , V_85 , V_106 ) ;
if ( ! V_85 )
return V_106 ;
V_91 = F_77 ( V_31 , V_85 , NULL ) ;
F_102 ( V_31 -> V_99 , V_91 , V_106 ) ;
return V_91 ;
}
static void * F_103 ( struct V_107 * V_108 , T_6 * V_109 )
{
return * V_109 ? NULL : V_110 ;
}
static void *
F_104 ( struct V_107 * V_108 , void * V_111 , T_6 * V_109 )
{
return NULL ;
}
static int F_105 ( struct V_107 * V_108 , void * V_111 )
{
struct V_30 * V_31 = V_108 -> V_112 ;
struct V_75 * V_87 = & V_31 -> V_41 ;
struct V_28 * V_29 , * V_113 = NULL ;
unsigned int V_114 = 0 ;
if ( V_111 != V_110 )
return 0 ;
F_28 ( & V_31 -> V_34 ) ;
F_106 (ei, &sbi->s_es_list, i_es_list) {
V_114 ++ ;
if ( V_113 && V_113 -> V_43 < V_29 -> V_43 )
V_113 = V_29 ;
else if ( ! V_113 )
V_113 = V_29 ;
}
F_30 ( & V_31 -> V_34 ) ;
F_107 ( V_108 , L_30 ,
F_108 ( & V_87 -> V_44 ) ,
F_108 ( & V_87 -> V_42 ) ) ;
F_107 ( V_108 , L_31 ,
V_87 -> V_78 ,
V_87 -> V_79 ) ;
if ( V_114 )
F_107 ( V_108 , L_32 , V_114 ) ;
F_107 ( V_108 , L_33 ,
F_109 ( V_87 -> V_96 , 1000 ) ) ;
F_107 ( V_108 , L_34 , V_87 -> V_98 ) ;
if ( V_114 )
F_107 ( V_108 ,
L_35
L_36 ,
V_113 -> V_94 . V_14 , V_113 -> V_43 , V_113 -> V_40 ,
F_109 ( V_87 -> V_97 , 1000 ) ) ;
return 0 ;
}
static void F_110 ( struct V_107 * V_108 , void * V_111 )
{
}
static int
F_111 ( struct V_10 * V_10 , struct V_115 * V_115 )
{
int V_106 ;
V_106 = F_112 ( V_115 , & V_116 ) ;
if ( ! V_106 ) {
struct V_107 * V_117 = V_115 -> V_118 ;
V_117 -> V_112 = F_113 ( V_10 ) ;
}
return V_106 ;
}
static int
F_114 ( struct V_10 * V_10 , struct V_115 * V_115 )
{
return F_115 ( V_10 , V_115 ) ;
}
int F_116 ( struct V_30 * V_31 )
{
int V_73 ;
F_117 ( V_119 < 48 ) ;
F_118 ( & V_31 -> V_35 ) ;
V_31 -> V_36 = 0 ;
F_119 ( & V_31 -> V_34 ) ;
V_31 -> V_41 . V_98 = 0 ;
V_31 -> V_41 . V_78 = 0 ;
V_31 -> V_41 . V_79 = 0 ;
V_31 -> V_41 . V_96 = 0 ;
V_31 -> V_41 . V_97 = 0 ;
V_73 = F_120 ( & V_31 -> V_41 . V_44 , 0 , V_120 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_120 ( & V_31 -> V_41 . V_42 , 0 , V_120 ) ;
if ( V_73 )
goto V_121;
V_31 -> V_105 . V_122 = F_100 ;
V_31 -> V_105 . V_123 = F_96 ;
V_31 -> V_105 . V_124 = V_125 ;
V_73 = F_121 ( & V_31 -> V_105 ) ;
if ( V_73 )
goto V_126;
if ( V_31 -> V_127 )
F_122 ( L_37 , V_128 , V_31 -> V_127 ,
& V_129 , V_31 ) ;
return 0 ;
V_126:
F_123 ( & V_31 -> V_41 . V_42 ) ;
V_121:
F_123 ( & V_31 -> V_41 . V_44 ) ;
return V_73 ;
}
void F_124 ( struct V_30 * V_31 )
{
if ( V_31 -> V_127 )
F_125 ( L_37 , V_31 -> V_127 ) ;
F_123 ( & V_31 -> V_41 . V_44 ) ;
F_123 ( & V_31 -> V_41 . V_42 ) ;
F_126 ( & V_31 -> V_105 ) ;
}
static int F_127 ( struct V_28 * V_29 , T_2 V_23 ,
int * V_85 , int * V_91 )
{
struct V_10 * V_10 = & V_29 -> V_94 ;
struct V_5 * V_6 = & V_29 -> V_15 ;
struct V_2 * V_16 ;
struct V_11 * V_12 ;
V_16 = F_16 ( & V_6 -> V_7 , V_29 -> V_130 ) ;
if ( ! V_16 )
goto V_131;
V_12 = & V_16 -> V_11 ;
while ( * V_85 > 0 ) {
if ( V_16 -> V_17 > V_23 ) {
V_29 -> V_130 = V_23 + 1 ;
return 0 ;
}
( * V_85 ) -- ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( F_22 ( V_16 ) )
goto V_132;
if ( F_49 ( V_16 ) ) {
F_128 ( V_16 ) ;
goto V_132;
}
F_51 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_37 ( V_10 , V_16 ) ;
( * V_91 ) ++ ;
V_132:
if ( ! V_12 )
goto V_131;
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
V_29 -> V_130 = V_16 -> V_17 ;
return 1 ;
V_131:
V_29 -> V_130 = 0 ;
return 0 ;
}
static int F_91 ( struct V_28 * V_29 , int * V_85 )
{
struct V_10 * V_10 = & V_29 -> V_94 ;
int V_91 = 0 ;
T_2 V_133 = V_29 -> V_130 ;
static F_129 ( V_134 , V_135 ,
V_136 ) ;
if ( V_29 -> V_40 == 0 )
return 0 ;
if ( F_89 ( V_10 , V_95 ) &&
F_130 ( & V_134 ) )
F_131 ( V_10 -> V_32 , L_38 ) ;
if ( ! F_127 ( V_29 , V_47 , V_85 , & V_91 ) &&
V_133 != 0 )
F_127 ( V_29 , V_133 - 1 , V_85 , & V_91 ) ;
V_29 -> V_15 . V_9 = NULL ;
return V_91 ;
}
