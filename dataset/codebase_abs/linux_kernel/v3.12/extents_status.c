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
if ( ( ( V_35 ) V_24 -> V_18 ) + V_34 -> V_18 > 0xFFFFFFFFULL )
return 0 ;
if ( ( ( V_35 ) V_24 -> V_17 ) + V_24 -> V_18 != V_34 -> V_17 )
return 0 ;
if ( ( F_33 ( V_24 ) || F_34 ( V_24 ) ) &&
( F_11 ( V_24 ) + V_24 -> V_18 == F_11 ( V_34 ) ) )
return 1 ;
if ( F_35 ( V_24 ) )
return 1 ;
if ( F_22 ( V_24 ) && ! F_34 ( V_24 ) )
return 1 ;
return 0 ;
}
static struct V_2 *
F_36 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_24 ;
struct V_11 * V_12 ;
V_12 = F_37 ( & V_16 -> V_11 ) ;
if ( ! V_12 )
return V_16 ;
V_24 = F_10 ( V_12 , struct V_2 , V_11 ) ;
if ( F_32 ( V_24 , V_16 ) ) {
V_24 -> V_18 += V_16 -> V_18 ;
F_38 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
V_16 = V_24 ;
}
return V_16 ;
}
static struct V_2 *
F_39 ( struct V_10 * V_10 , struct V_2 * V_16 )
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
F_38 ( V_12 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_24 ) ;
}
return V_16 ;
}
static void F_40 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_36 * V_37 = NULL ;
struct V_38 * V_39 ;
T_2 V_40 ;
T_3 V_41 ;
unsigned short V_42 ;
int V_43 , V_44 , V_45 ;
V_37 = F_41 ( V_10 , V_16 -> V_17 , NULL , V_46 ) ;
if ( F_42 ( V_37 ) )
return;
V_43 = F_43 ( V_10 ) ;
V_39 = V_37 [ V_43 ] . V_47 ;
if ( V_39 ) {
V_40 = F_44 ( V_39 -> V_40 ) ;
V_41 = F_45 ( V_39 ) ;
V_42 = F_46 ( V_39 ) ;
V_44 = F_47 ( V_39 ) ? 1 : 0 ;
V_45 = F_34 ( V_16 ) ? 1 : 0 ;
if ( ! F_33 ( V_16 ) && ! F_34 ( V_16 ) ) {
if ( F_20 ( V_16 -> V_17 , V_40 , V_42 ) ) {
F_48 ( L_6
L_7
L_8
L_9
L_10 ,
V_10 -> V_14 , V_40 , V_42 ,
V_41 , V_44 ? 'u' : 'w' ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
goto V_27;
}
if ( V_16 -> V_17 < V_40 ||
F_11 ( V_16 ) != V_41 + V_16 -> V_17 - V_40 ) {
F_48 ( L_11
L_12
L_13 , V_10 -> V_14 ,
V_40 , V_42 , V_41 ,
V_44 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_45 ? 'u' : 'w' ) ;
goto V_27;
}
if ( V_44 ^ V_45 ) {
F_48 ( L_11
L_12
L_13 , V_10 -> V_14 ,
V_40 , V_42 , V_41 ,
V_44 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_45 ? 'u' : 'w' ) ;
}
} else {
if ( ! F_22 ( V_16 ) && ! F_35 ( V_16 ) ) {
F_48 ( L_11
L_14
L_15
L_10 , V_10 -> V_14 ,
V_16 -> V_17 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
}
V_27:
if ( V_37 ) {
F_49 ( V_37 ) ;
F_50 ( V_37 ) ;
}
}
static void F_51 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_48 V_49 ;
int V_50 ;
V_49 . V_51 = V_16 -> V_17 ;
V_49 . V_52 = V_16 -> V_18 ;
V_50 = F_52 ( NULL , V_10 , & V_49 , 0 ) ;
if ( V_50 > 0 ) {
if ( F_22 ( V_16 ) || F_35 ( V_16 ) ) {
F_48 ( L_11
L_16
L_17 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
} else if ( F_33 ( V_16 ) ) {
if ( V_50 != V_16 -> V_18 ) {
F_48 ( L_6
L_18 ,
V_10 -> V_14 , V_50 , V_16 -> V_18 ) ;
return;
}
if ( V_49 . V_53 != F_11 ( V_16 ) ) {
F_48 ( L_6
L_19
L_20 ,
V_10 -> V_14 , V_49 . V_53 ,
F_11 ( V_16 ) ) ;
return;
}
} else {
F_15 ( 1 ) ;
}
} else if ( V_50 == 0 ) {
if ( F_33 ( V_16 ) ) {
F_48 ( L_11
L_21
L_22 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
}
}
}
static inline void F_53 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
F_15 ( ! F_54 ( & F_8 ( V_10 ) -> V_54 ) ) ;
if ( F_55 ( V_10 , V_55 ) )
F_40 ( V_10 , V_16 ) ;
else
F_51 ( V_10 , V_16 ) ;
}
static inline void F_53 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
}
static int F_56 ( struct V_10 * V_10 , struct V_2 * V_56 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * * V_57 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_58 = NULL ;
struct V_2 * V_16 ;
while ( * V_57 ) {
V_58 = * V_57 ;
V_16 = F_10 ( V_58 , struct V_2 , V_11 ) ;
if ( V_56 -> V_17 < V_16 -> V_17 ) {
if ( F_32 ( V_56 , V_16 ) ) {
V_16 -> V_17 = V_56 -> V_17 ;
V_16 -> V_18 += V_56 -> V_18 ;
if ( F_33 ( V_16 ) ||
F_34 ( V_16 ) )
F_57 ( V_16 ,
V_56 -> V_26 ) ;
V_16 = F_36 ( V_10 , V_16 ) ;
goto V_27;
}
V_57 = & ( * V_57 ) -> V_21 ;
} else if ( V_56 -> V_17 > F_14 ( V_16 ) ) {
if ( F_32 ( V_16 , V_56 ) ) {
V_16 -> V_18 += V_56 -> V_18 ;
V_16 = F_39 ( V_10 , V_16 ) ;
goto V_27;
}
V_57 = & ( * V_57 ) -> V_22 ;
} else {
F_15 ( 1 ) ;
return - V_59 ;
}
}
V_16 = F_25 ( V_10 , V_56 -> V_17 , V_56 -> V_18 ,
V_56 -> V_26 ) ;
if ( ! V_16 )
return - V_4 ;
F_58 ( & V_16 -> V_11 , V_58 , V_57 ) ;
F_59 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_27:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_60 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_60 )
{
struct V_2 V_56 ;
T_2 V_23 = V_20 + V_28 - 1 ;
int V_61 = 0 ;
F_21 ( L_23 ,
V_20 , V_28 , V_29 , V_60 , V_10 -> V_14 ) ;
if ( ! V_28 )
return 0 ;
F_15 ( V_23 < V_20 ) ;
V_56 . V_17 = V_20 ;
V_56 . V_18 = V_28 ;
F_57 ( & V_56 , V_29 ) ;
F_61 ( & V_56 , V_60 ) ;
F_62 ( V_10 , & V_56 ) ;
F_53 ( V_10 , & V_56 ) ;
F_63 ( & F_8 ( V_10 ) -> V_25 ) ;
V_61 = F_64 ( V_10 , V_20 , V_23 ) ;
if ( V_61 != 0 )
goto error;
V_62:
V_61 = F_56 ( V_10 , & V_56 ) ;
if ( V_61 == - V_4 && F_65 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_62;
if ( V_61 == - V_4 && ! F_22 ( & V_56 ) )
V_61 = 0 ;
error:
F_66 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_61 ;
}
void F_67 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_60 )
{
struct V_2 * V_16 ;
struct V_2 V_56 ;
T_2 V_23 = V_20 + V_28 - 1 ;
V_56 . V_17 = V_20 ;
V_56 . V_18 = V_28 ;
F_57 ( & V_56 , V_29 ) ;
F_61 ( & V_56 , V_60 ) ;
F_68 ( V_10 , & V_56 ) ;
if ( ! V_28 )
return;
F_15 ( V_23 < V_20 ) ;
F_63 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 = F_16 ( & F_8 ( V_10 ) -> V_15 . V_7 , V_20 ) ;
if ( ! V_16 || V_16 -> V_17 > V_23 )
F_56 ( V_10 , & V_56 ) ;
F_66 ( & F_8 ( V_10 ) -> V_25 ) ;
}
int F_69 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
int V_63 = 0 ;
F_70 ( V_10 , V_20 ) ;
F_21 ( L_24 , V_20 ) ;
V_6 = & F_8 ( V_10 ) -> V_15 ;
F_19 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 -> V_17 = V_16 -> V_18 = V_16 -> V_26 = 0 ;
if ( V_6 -> V_9 ) {
V_24 = V_6 -> V_9 ;
if ( F_20 ( V_20 , V_24 -> V_17 , V_24 -> V_18 ) ) {
F_21 ( L_25 ,
V_20 , V_24 -> V_17 , V_24 -> V_18 ) ;
V_63 = 1 ;
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
V_63 = 1 ;
break;
}
}
V_27:
if ( V_63 ) {
F_15 ( ! V_24 ) ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_71 ( V_10 , V_16 , V_63 ) ;
return V_63 ;
}
static int F_64 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_23 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_64 ;
T_2 V_65 , V_66 ;
T_3 V_67 ;
int V_61 ;
V_62:
V_61 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_23 )
goto V_27;
V_6 -> V_9 = NULL ;
V_64 . V_17 = V_16 -> V_17 ;
V_64 . V_18 = V_16 -> V_18 ;
V_64 . V_26 = V_16 -> V_26 ;
V_65 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_66 = F_14 ( V_16 ) > V_23 ? F_14 ( V_16 ) - V_23 : 0 ;
if ( V_65 > 0 )
V_16 -> V_18 = V_65 ;
if ( V_66 > 0 ) {
if ( V_65 > 0 ) {
struct V_2 V_56 ;
V_56 . V_17 = V_23 + 1 ;
V_56 . V_18 = V_66 ;
if ( F_33 ( & V_64 ) ||
F_34 ( & V_64 ) ) {
V_67 = F_11 ( & V_64 ) +
V_64 . V_18 - V_66 ;
F_57 ( & V_56 , V_67 ) ;
}
F_61 ( & V_56 , F_12 ( & V_64 ) ) ;
V_61 = F_56 ( V_10 , & V_56 ) ;
if ( V_61 ) {
V_16 -> V_17 = V_64 . V_17 ;
V_16 -> V_18 = V_64 . V_18 ;
if ( ( V_61 == - V_4 ) &&
F_65 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_62;
goto V_27;
}
} else {
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_66 ;
if ( F_33 ( V_16 ) ||
F_34 ( V_16 ) ) {
V_67 = V_64 . V_26 + V_64 . V_18 - V_66 ;
F_57 ( V_16 , V_67 ) ;
}
}
goto V_27;
}
if ( V_65 > 0 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( V_12 )
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
else
V_16 = NULL ;
}
while ( V_16 && F_14 ( V_16 ) <= V_23 ) {
V_12 = F_13 ( & V_16 -> V_11 ) ;
F_38 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
if ( ! V_12 ) {
V_16 = NULL ;
break;
}
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
}
if ( V_16 && V_16 -> V_17 < V_23 + 1 ) {
T_2 V_68 = V_16 -> V_18 ;
V_65 = F_14 ( V_16 ) - V_23 ;
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_65 ;
if ( F_33 ( V_16 ) || F_34 ( V_16 ) ) {
V_67 = V_16 -> V_26 + V_68 - V_65 ;
F_57 ( V_16 , V_67 ) ;
}
}
V_27:
return V_61 ;
}
int F_72 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 )
{
T_2 V_23 ;
int V_61 = 0 ;
F_73 ( V_10 , V_20 , V_28 ) ;
F_21 ( L_26 ,
V_20 , V_28 , V_10 -> V_14 ) ;
if ( ! V_28 )
return V_61 ;
V_23 = V_20 + V_28 - 1 ;
F_15 ( V_23 < V_20 ) ;
F_63 ( & F_8 ( V_10 ) -> V_25 ) ;
V_61 = F_64 ( V_10 , V_20 , V_23 ) ;
F_66 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_61 ;
}
static int F_74 ( void * V_69 , struct V_70 * V_71 ,
struct V_70 * V_72 )
{
struct V_73 * V_74 , * V_75 ;
V_74 = F_75 ( V_71 , struct V_73 , V_76 ) ;
V_75 = F_75 ( V_72 , struct V_73 , V_76 ) ;
if ( F_76 ( & V_74 -> V_77 , V_78 ) &&
! F_76 ( & V_75 -> V_77 , V_78 ) )
return 1 ;
if ( ! F_76 ( & V_74 -> V_77 , V_78 ) &&
F_76 ( & V_75 -> V_77 , V_78 ) )
return - 1 ;
if ( V_74 -> V_79 == V_75 -> V_79 )
return 0 ;
if ( F_77 ( V_74 -> V_79 , V_75 -> V_79 ) )
return 1 ;
else
return - 1 ;
}
static int F_65 ( struct V_80 * V_81 , int V_82 ,
struct V_73 * V_83 )
{
struct V_73 * V_84 ;
struct V_70 * V_85 , * V_86 ;
F_78 ( V_87 ) ;
int V_88 = 0 ;
int V_89 = 0 , V_90 = 1 , V_91 = 0 ;
F_79 ( & V_81 -> V_92 ) ;
V_62:
F_80 (cur, tmp, &sbi->s_es_lru) {
int V_93 ;
if ( F_81 ( & V_81 -> V_33 ) == 0 )
break;
V_84 = F_75 ( V_85 , struct V_73 , V_76 ) ;
if ( ( V_81 -> V_94 < V_84 -> V_79 ) ||
( V_90 && F_76 ( & V_84 -> V_77 ,
V_78 ) ) ) {
V_91 ++ ;
F_82 ( V_85 , & V_87 ) ;
continue;
}
if ( V_84 -> V_31 == 0 || V_84 == V_83 )
continue;
F_63 ( & V_84 -> V_25 ) ;
V_93 = F_83 ( V_84 , V_82 ) ;
if ( V_84 -> V_31 == 0 )
F_84 ( & V_84 -> V_76 ) ;
F_66 ( & V_84 -> V_25 ) ;
V_88 += V_93 ;
V_82 -= V_93 ;
if ( V_82 == 0 )
break;
}
F_85 ( & V_87 , & V_81 -> V_95 ) ;
F_86 ( & V_87 ) ;
if ( ( V_88 == 0 ) && V_91 && ! V_89 ) {
V_89 ++ ;
F_87 ( NULL , & V_81 -> V_95 , F_74 ) ;
V_81 -> V_94 = V_96 ;
V_84 = F_88 ( & V_81 -> V_95 , struct V_73 ,
V_76 ) ;
if ( F_76 ( & V_84 -> V_77 ,
V_78 ) )
V_90 = 0 ;
goto V_62;
}
F_89 ( & V_81 -> V_92 ) ;
if ( V_83 && V_88 == 0 )
V_88 = F_83 ( V_83 , V_82 ) ;
return V_88 ;
}
static unsigned long F_90 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
unsigned long V_101 ;
struct V_80 * V_81 ;
V_81 = F_91 ( V_98 , struct V_80 , V_102 ) ;
V_101 = F_81 ( & V_81 -> V_33 ) ;
F_92 ( V_81 -> V_103 , V_100 -> V_82 , V_101 ) ;
return V_101 ;
}
static unsigned long F_93 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
struct V_80 * V_81 = F_91 ( V_98 ,
struct V_80 , V_102 ) ;
int V_82 = V_100 -> V_82 ;
int V_104 , V_88 ;
V_104 = F_81 ( & V_81 -> V_33 ) ;
F_92 ( V_81 -> V_103 , V_82 , V_104 ) ;
if ( ! V_82 )
return V_104 ;
V_88 = F_65 ( V_81 , V_82 , NULL ) ;
F_94 ( V_81 -> V_103 , V_88 , V_104 ) ;
return V_88 ;
}
void F_95 ( struct V_80 * V_81 )
{
F_86 ( & V_81 -> V_95 ) ;
F_96 ( & V_81 -> V_92 ) ;
V_81 -> V_94 = 0 ;
V_81 -> V_102 . V_105 = F_93 ;
V_81 -> V_102 . V_106 = F_90 ;
V_81 -> V_102 . V_107 = V_108 ;
F_97 ( & V_81 -> V_102 ) ;
}
void F_98 ( struct V_80 * V_81 )
{
F_99 ( & V_81 -> V_102 ) ;
}
void F_100 ( struct V_10 * V_10 )
{
struct V_73 * V_84 = F_8 ( V_10 ) ;
struct V_80 * V_81 = F_28 ( V_10 -> V_32 ) ;
V_84 -> V_79 = V_96 ;
if ( ! F_101 ( & V_84 -> V_76 ) )
return;
F_79 ( & V_81 -> V_92 ) ;
if ( F_101 ( & V_84 -> V_76 ) )
F_102 ( & V_84 -> V_76 , & V_81 -> V_95 ) ;
F_89 ( & V_81 -> V_92 ) ;
}
void F_103 ( struct V_10 * V_10 )
{
struct V_73 * V_84 = F_8 ( V_10 ) ;
struct V_80 * V_81 = F_28 ( V_10 -> V_32 ) ;
F_79 ( & V_81 -> V_92 ) ;
if ( ! F_101 ( & V_84 -> V_76 ) )
F_84 ( & V_84 -> V_76 ) ;
F_89 ( & V_81 -> V_92 ) ;
}
static int F_83 ( struct V_73 * V_84 ,
int V_82 )
{
struct V_10 * V_10 = & V_84 -> V_77 ;
struct V_5 * V_6 = & V_84 -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
unsigned long V_88 = 0 ;
static F_104 ( V_109 , V_110 ,
V_111 ) ;
if ( V_84 -> V_31 == 0 )
return 0 ;
if ( F_76 ( V_10 , V_78 ) &&
F_105 ( & V_109 ) )
F_106 ( V_10 -> V_32 , L_27 ) ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 != NULL ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! F_22 ( V_16 ) ) {
F_38 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
V_88 ++ ;
if ( -- V_82 == 0 )
break;
}
}
V_6 -> V_9 = NULL ;
return V_88 ;
}
