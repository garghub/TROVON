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
static struct V_2 *
F_25 ( struct V_10 * V_10 , T_2 V_20 , T_2 V_28 ,
T_3 V_29 )
{
struct V_2 * V_16 ;
V_16 = F_26 ( V_1 , V_30 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_17 = V_20 ;
V_16 -> V_18 = V_28 ;
V_16 -> V_26 = V_29 ;
if ( ! F_22 ( V_16 ) ) {
F_8 ( V_10 ) -> V_31 ++ ;
F_27 ( & F_28 ( V_10 -> V_32 ) -> V_33 ) ;
}
return V_16 ;
}
static void F_29 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
if ( ! F_22 ( V_16 ) ) {
F_15 ( F_8 ( V_10 ) -> V_31 == 0 ) ;
F_8 ( V_10 ) -> V_31 -- ;
F_30 ( & F_28 ( V_10 -> V_32 ) -> V_33 ) ;
}
F_31 ( V_1 , V_16 ) ;
}
static int F_32 ( struct V_2 * V_24 ,
struct V_2 * V_34 )
{
if ( F_12 ( V_24 ) != F_12 ( V_34 ) )
return 0 ;
if ( ( ( V_35 ) V_24 -> V_18 ) + V_34 -> V_18 > V_36 ) {
F_33 ( L_6
L_7
L_8 ,
V_24 -> V_18 , V_34 -> V_18 , V_36 ) ;
F_34 ( 1 ) ;
return 0 ;
}
if ( ( ( V_35 ) V_24 -> V_17 ) + V_24 -> V_18 != V_34 -> V_17 )
return 0 ;
if ( ( F_35 ( V_24 ) || F_36 ( V_24 ) ) &&
( F_11 ( V_24 ) + V_24 -> V_18 == F_11 ( V_34 ) ) )
return 1 ;
if ( F_37 ( V_24 ) )
return 1 ;
if ( F_22 ( V_24 ) && ! F_36 ( V_24 ) )
return 1 ;
return 0 ;
}
static struct V_2 *
F_38 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_24 ;
struct V_11 * V_12 ;
V_12 = F_39 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_32 ( V_24 , V_16 ) ) {
V_24 -> V_18 += V_16 -> V_18 ;
F_40 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
V_16 = V_24 ;
}
return V_16 ;
}
static struct V_2 *
F_41 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_24 ;
struct V_11 * V_12 ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_32 ( V_16 , V_24 ) ) {
V_16 -> V_18 += V_24 -> V_18 ;
F_40 ( V_12 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_24 ) ;
}
return V_16 ;
}
static void F_42 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
T_2 V_41 ;
T_3 V_42 ;
unsigned short V_43 ;
int V_44 , V_45 , V_46 ;
V_38 = F_43 ( V_10 , V_16 -> V_17 , NULL , V_47 ) ;
if ( F_44 ( V_38 ) )
return;
V_44 = F_45 ( V_10 ) ;
V_40 = V_38 [ V_44 ] . V_48 ;
if ( V_40 ) {
V_41 = F_46 ( V_40 -> V_41 ) ;
V_42 = F_47 ( V_40 ) ;
V_43 = F_48 ( V_40 ) ;
V_45 = F_49 ( V_40 ) ? 1 : 0 ;
V_46 = F_36 ( V_16 ) ? 1 : 0 ;
if ( ! F_35 ( V_16 ) && ! F_36 ( V_16 ) ) {
if ( F_20 ( V_16 -> V_17 , V_41 , V_43 ) ) {
F_33 ( L_9
L_10
L_11
L_12
L_13 ,
V_10 -> V_14 , V_41 , V_43 ,
V_42 , V_45 ? 'u' : 'w' ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
goto V_27;
}
if ( V_16 -> V_17 < V_41 ||
F_11 ( V_16 ) != V_42 + V_16 -> V_17 - V_41 ) {
F_33 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_41 , V_43 , V_42 ,
V_45 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_46 ? 'u' : 'w' ) ;
goto V_27;
}
if ( V_45 ^ V_46 ) {
F_33 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_41 , V_43 , V_42 ,
V_45 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_46 ? 'u' : 'w' ) ;
}
} else {
if ( ! F_22 ( V_16 ) && ! F_37 ( V_16 ) ) {
F_33 ( L_14
L_17
L_18
L_13 , V_10 -> V_14 ,
V_16 -> V_17 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
}
V_27:
if ( V_38 ) {
F_50 ( V_38 ) ;
F_51 ( V_38 ) ;
}
}
static void F_52 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_49 V_50 ;
int V_51 ;
V_50 . V_52 = V_16 -> V_17 ;
V_50 . V_53 = V_16 -> V_18 ;
V_51 = F_53 ( NULL , V_10 , & V_50 , 0 ) ;
if ( V_51 > 0 ) {
if ( F_22 ( V_16 ) || F_37 ( V_16 ) ) {
F_33 ( L_14
L_19
L_20 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
} else if ( F_35 ( V_16 ) ) {
if ( V_51 != V_16 -> V_18 ) {
F_33 ( L_9
L_21 ,
V_10 -> V_14 , V_51 , V_16 -> V_18 ) ;
return;
}
if ( V_50 . V_54 != F_11 ( V_16 ) ) {
F_33 ( L_9
L_22
L_23 ,
V_10 -> V_14 , V_50 . V_54 ,
F_11 ( V_16 ) ) ;
return;
}
} else {
F_15 ( 1 ) ;
}
} else if ( V_51 == 0 ) {
if ( F_35 ( V_16 ) ) {
F_33 ( L_14
L_24
L_25 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
}
}
}
static inline void F_54 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
F_15 ( ! F_55 ( & F_8 ( V_10 ) -> V_55 ) ) ;
if ( F_56 ( V_10 , V_56 ) )
F_42 ( V_10 , V_16 ) ;
else
F_52 ( V_10 , V_16 ) ;
}
static inline void F_54 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
}
static int F_57 ( struct V_10 * V_10 , struct V_2 * V_57 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * * V_58 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_59 = NULL ;
struct V_2 * V_16 ;
while ( * V_58 ) {
V_59 = * V_58 ;
V_16 = F_10 ( V_59 , struct V_2 , V_11 ) ;
if ( V_57 -> V_17 < V_16 -> V_17 ) {
if ( F_32 ( V_57 , V_16 ) ) {
V_16 -> V_17 = V_57 -> V_17 ;
V_16 -> V_18 += V_57 -> V_18 ;
if ( F_35 ( V_16 ) ||
F_36 ( V_16 ) )
F_58 ( V_16 ,
V_57 -> V_26 ) ;
V_16 = F_38 ( V_10 , V_16 ) ;
goto V_27;
}
V_58 = & ( * V_58 ) -> V_21 ;
} else if ( V_57 -> V_17 > F_14 ( V_16 ) ) {
if ( F_32 ( V_16 , V_57 ) ) {
V_16 -> V_18 += V_57 -> V_18 ;
V_16 = F_41 ( V_10 , V_16 ) ;
goto V_27;
}
V_58 = & ( * V_58 ) -> V_22 ;
} else {
F_15 ( 1 ) ;
return - V_60 ;
}
}
V_16 = F_25 ( V_10 , V_57 -> V_17 , V_57 -> V_18 ,
V_57 -> V_26 ) ;
if ( ! V_16 )
return - V_4 ;
F_59 ( & V_16 -> V_11 , V_59 , V_58 ) ;
F_60 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_27:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_61 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_61 )
{
struct V_2 V_57 ;
T_2 V_23 = V_20 + V_28 - 1 ;
int V_62 = 0 ;
F_21 ( L_26 ,
V_20 , V_28 , V_29 , V_61 , V_10 -> V_14 ) ;
if ( ! V_28 )
return 0 ;
F_15 ( V_23 < V_20 ) ;
V_57 . V_17 = V_20 ;
V_57 . V_18 = V_28 ;
F_62 ( & V_57 , V_29 , V_61 ) ;
F_63 ( V_10 , & V_57 ) ;
F_54 ( V_10 , & V_57 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_62 = F_65 ( V_10 , V_20 , V_23 ) ;
if ( V_62 != 0 )
goto error;
V_63:
V_62 = F_57 ( V_10 , & V_57 ) ;
if ( V_62 == - V_4 && F_66 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_63;
if ( V_62 == - V_4 && ! F_22 ( & V_57 ) )
V_62 = 0 ;
error:
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_62 ;
}
void F_68 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_61 )
{
struct V_2 * V_16 ;
struct V_2 V_57 ;
T_2 V_23 = V_20 + V_28 - 1 ;
V_57 . V_17 = V_20 ;
V_57 . V_18 = V_28 ;
F_62 ( & V_57 , V_29 , V_61 ) ;
F_69 ( V_10 , & V_57 ) ;
if ( ! V_28 )
return;
F_15 ( V_23 < V_20 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 = F_16 ( & F_8 ( V_10 ) -> V_15 . V_7 , V_20 ) ;
if ( ! V_16 || V_16 -> V_17 > V_23 )
F_57 ( V_10 , & V_57 ) ;
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
}
int F_70 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
int V_64 = 0 ;
F_71 ( V_10 , V_20 ) ;
F_21 ( L_27 , V_20 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
F_19 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_26 = 0 ;
if ( V_6 -> V_9 ) {
V_24 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_24 -> V_17 , V_24 -> V_18 ) ) {
F_21 ( L_28 ,
V_20 , V_24 -> V_17 , V_24 -> V_18 ) ;
V_64 = 1 ;
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
V_64 = 1 ;
break;
}
}
V_27:
if ( V_64 ) {
F_15 ( ! V_24 ) ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_72 ( V_10 , V_16 , V_64 ) ;
return V_64 ;
}
static int F_65 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_23 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_65 ;
T_2 V_66 , V_67 ;
T_3 V_68 ;
int V_62 ;
V_63:
V_62 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_23 )
goto V_27;
V_6 -> V_9 = NULL ;
V_65 . V_17 = V_16 -> V_17 ;
V_65 . V_18 = V_16 -> V_18 ;
V_65 . V_26 = V_16 -> V_26 ;
V_66 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_67 = F_14 ( V_16 ) > V_23 ? F_14 ( V_16 ) - V_23 : 0 ;
if ( V_66 > 0 )
V_16 -> V_18 = V_66 ;
if ( V_67 > 0 ) {
if ( V_66 > 0 ) {
struct V_2 V_57 ;
V_57 . V_17 = V_23 + 1 ;
V_57 . V_18 = V_67 ;
V_68 = 0x7FDEADBEEFULL ;
if ( F_35 ( & V_65 ) ||
F_36 ( & V_65 ) )
V_68 = F_11 ( & V_65 ) +
V_65 . V_18 - V_67 ;
F_62 ( & V_57 , V_68 ,
F_12 ( & V_65 ) ) ;
V_62 = F_57 ( V_10 , & V_57 ) ;
if ( V_62 ) {
V_16 -> V_17 = V_65 . V_17 ;
V_16 -> V_18 = V_65 . V_18 ;
if ( ( V_62 == - V_4 ) &&
F_66 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_63;
goto V_27;
}
} else {
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_67 ;
if ( F_35 ( V_16 ) ||
F_36 ( V_16 ) ) {
V_68 = V_65 . V_26 + V_65 . V_18 - V_67 ;
F_58 ( V_16 , V_68 ) ;
}
}
goto V_27;
}
if ( V_66 > 0 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( V_12 )
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
else
V_16 = NULL ;
}
while ( V_16 && F_14 ( V_16 ) <= V_23 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
F_40 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
if ( ! V_12 ) {
V_16 = NULL ;
break;
}
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
if ( V_16 && V_16 -> V_17 < V_23 + 1 ) {
T_2 V_69 = V_16 -> V_18 ;
V_66 = F_14 ( V_16 ) - V_23 ;
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_66 ;
if ( F_35 ( V_16 ) || F_36 ( V_16 ) ) {
V_68 = V_16 -> V_26 + V_69 - V_66 ;
F_58 ( V_16 , V_68 ) ;
}
}
V_27:
return V_62 ;
}
int F_73 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 )
{
T_2 V_23 ;
int V_62 = 0 ;
F_74 ( V_10 , V_20 , V_28 ) ;
F_21 ( L_29 ,
V_20 , V_28 , V_10 -> V_14 ) ;
if ( ! V_28 )
return V_62 ;
V_23 = V_20 + V_28 - 1 ;
F_15 ( V_23 < V_20 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_62 = F_65 ( V_10 , V_20 , V_23 ) ;
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_62 ;
}
static int F_75 ( void * V_70 , struct V_71 * V_72 ,
struct V_71 * V_73 )
{
struct V_74 * V_75 , * V_76 ;
V_75 = F_76 ( V_72 , struct V_74 , V_77 ) ;
V_76 = F_76 ( V_73 , struct V_74 , V_77 ) ;
if ( F_77 ( & V_75 -> V_78 , V_79 ) &&
! F_77 ( & V_76 -> V_78 , V_79 ) )
return 1 ;
if ( ! F_77 ( & V_75 -> V_78 , V_79 ) &&
F_77 ( & V_76 -> V_78 , V_79 ) )
return - 1 ;
if ( V_75 -> V_80 == V_76 -> V_80 )
return 0 ;
if ( F_78 ( V_75 -> V_80 , V_76 -> V_80 ) )
return 1 ;
else
return - 1 ;
}
static int F_66 ( struct V_81 * V_82 , int V_83 ,
struct V_74 * V_84 )
{
struct V_74 * V_85 ;
struct V_71 * V_86 , * V_87 ;
F_79 ( V_88 ) ;
int V_89 = 0 ;
int V_90 = 0 , V_91 = 1 , V_92 = 0 ;
F_80 ( & V_82 -> V_93 ) ;
V_63:
F_81 (cur, tmp, &sbi->s_es_lru) {
int V_94 ;
if ( F_82 ( & V_82 -> V_33 ) == 0 )
break;
V_85 = F_76 ( V_86 , struct V_74 , V_77 ) ;
if ( ( V_82 -> V_95 < V_85 -> V_80 ) ||
( V_91 && F_77 ( & V_85 -> V_78 ,
V_79 ) ) ) {
V_92 ++ ;
F_83 ( V_86 , & V_88 ) ;
continue;
}
if ( V_85 -> V_31 == 0 || V_85 == V_84 ||
! F_84 ( & V_85 -> V_25 ) )
continue;
V_94 = F_85 ( V_85 , V_83 ) ;
if ( V_85 -> V_31 == 0 )
F_86 ( & V_85 -> V_77 ) ;
F_67 ( & V_85 -> V_25 ) ;
V_89 += V_94 ;
V_83 -= V_94 ;
if ( V_83 == 0 )
break;
}
F_87 ( & V_88 , & V_82 -> V_96 ) ;
F_88 ( & V_88 ) ;
if ( ( V_89 == 0 ) && V_92 && ! V_90 ) {
V_90 ++ ;
F_89 ( NULL , & V_82 -> V_96 , F_75 ) ;
V_82 -> V_95 = V_97 ;
V_85 = F_90 ( & V_82 -> V_96 , struct V_74 ,
V_77 ) ;
if ( F_77 ( & V_85 -> V_78 ,
V_79 ) )
V_91 = 0 ;
goto V_63;
}
F_91 ( & V_82 -> V_93 ) ;
if ( V_84 && V_89 == 0 )
V_89 = F_85 ( V_84 , V_83 ) ;
return V_89 ;
}
static unsigned long F_92 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
unsigned long V_102 ;
struct V_81 * V_82 ;
V_82 = F_93 ( V_99 , struct V_81 , V_103 ) ;
V_102 = F_82 ( & V_82 -> V_33 ) ;
F_94 ( V_82 -> V_104 , V_101 -> V_83 , V_102 ) ;
return V_102 ;
}
static unsigned long F_95 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_81 * V_82 = F_93 ( V_99 ,
struct V_81 , V_103 ) ;
int V_83 = V_101 -> V_83 ;
int V_105 , V_89 ;
V_105 = F_82 ( & V_82 -> V_33 ) ;
F_94 ( V_82 -> V_104 , V_83 , V_105 ) ;
if ( ! V_83 )
return V_105 ;
V_89 = F_66 ( V_82 , V_83 , NULL ) ;
F_96 ( V_82 -> V_104 , V_89 , V_105 ) ;
return V_89 ;
}
void F_97 ( struct V_81 * V_82 )
{
F_88 ( & V_82 -> V_96 ) ;
F_98 ( & V_82 -> V_93 ) ;
V_82 -> V_95 = 0 ;
V_82 -> V_103 . V_106 = F_95 ;
V_82 -> V_103 . V_107 = F_92 ;
V_82 -> V_103 . V_108 = V_109 ;
F_99 ( & V_82 -> V_103 ) ;
}
void F_100 ( struct V_81 * V_82 )
{
F_101 ( & V_82 -> V_103 ) ;
}
void F_102 ( struct V_10 * V_10 )
{
struct V_74 * V_85 = F_8 ( V_10 ) ;
struct V_81 * V_82 = F_28 ( V_10 -> V_32 ) ;
V_85 -> V_80 = V_97 ;
if ( ! F_103 ( & V_85 -> V_77 ) )
return;
F_80 ( & V_82 -> V_93 ) ;
if ( F_103 ( & V_85 -> V_77 ) )
F_104 ( & V_85 -> V_77 , & V_82 -> V_96 ) ;
F_91 ( & V_82 -> V_93 ) ;
}
void F_105 ( struct V_10 * V_10 )
{
struct V_74 * V_85 = F_8 ( V_10 ) ;
struct V_81 * V_82 = F_28 ( V_10 -> V_32 ) ;
F_80 ( & V_82 -> V_93 ) ;
if ( ! F_103 ( & V_85 -> V_77 ) )
F_86 ( & V_85 -> V_77 ) ;
F_91 ( & V_82 -> V_93 ) ;
}
static int F_85 ( struct V_74 * V_85 ,
int V_83 )
{
struct V_10 * V_10 = & V_85 -> V_78 ;
struct V_5 * V_6 = & V_85 -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
unsigned long V_89 = 0 ;
static F_106 ( V_110 , V_111 ,
V_112 ) ;
if ( V_85 -> V_31 == 0 )
return 0 ;
if ( F_77 ( V_10 , V_79 ) &&
F_107 ( & V_110 ) )
F_108 ( V_10 -> V_32 , L_30 ) ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 != NULL ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! F_22 ( V_16 ) ) {
F_40 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
V_89 ++ ;
if ( -- V_83 == 0 )
break;
}
}
V_6 -> V_9 = NULL ;
return V_89 ;
}
