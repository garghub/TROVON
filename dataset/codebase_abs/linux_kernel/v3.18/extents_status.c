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
F_27 ( & F_28 ( V_10 -> V_32 ) ->
V_33 . V_34 ) ;
}
F_8 ( V_10 ) -> V_35 ++ ;
F_27 ( & F_28 ( V_10 -> V_32 ) -> V_33 . V_36 ) ;
return V_16 ;
}
static void F_29 ( struct V_10 * V_10 , struct V_2 * V_16 )
{
F_8 ( V_10 ) -> V_35 -- ;
F_30 ( & F_28 ( V_10 -> V_32 ) -> V_33 . V_36 ) ;
if ( ! F_22 ( V_16 ) ) {
F_15 ( F_8 ( V_10 ) -> V_31 == 0 ) ;
F_8 ( V_10 ) -> V_31 -- ;
F_30 ( & F_28 ( V_10 -> V_32 ) ->
V_33 . V_34 ) ;
}
F_31 ( V_1 , V_16 ) ;
}
static int F_32 ( struct V_2 * V_24 ,
struct V_2 * V_37 )
{
if ( F_12 ( V_24 ) != F_12 ( V_37 ) )
return 0 ;
if ( ( ( V_38 ) V_24 -> V_18 ) + V_37 -> V_18 > V_39 ) {
F_33 ( L_6
L_7
L_8 ,
V_24 -> V_18 , V_37 -> V_18 , V_39 ) ;
F_34 ( 1 ) ;
return 0 ;
}
if ( ( ( V_38 ) V_24 -> V_17 ) + V_24 -> V_18 != V_37 -> V_17 )
return 0 ;
if ( ( F_35 ( V_24 ) || F_36 ( V_24 ) ) &&
( F_11 ( V_24 ) + V_24 -> V_18 == F_11 ( V_37 ) ) )
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
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 ;
T_2 V_44 ;
T_3 V_45 ;
unsigned short V_46 ;
int V_47 , V_48 , V_49 ;
V_41 = F_43 ( V_10 , V_16 -> V_17 , NULL , V_50 ) ;
if ( F_44 ( V_41 ) )
return;
V_47 = F_45 ( V_10 ) ;
V_43 = V_41 [ V_47 ] . V_51 ;
if ( V_43 ) {
V_44 = F_46 ( V_43 -> V_44 ) ;
V_45 = F_47 ( V_43 ) ;
V_46 = F_48 ( V_43 ) ;
V_48 = F_49 ( V_43 ) ? 1 : 0 ;
V_49 = F_36 ( V_16 ) ? 1 : 0 ;
if ( ! F_35 ( V_16 ) && ! F_36 ( V_16 ) ) {
if ( F_20 ( V_16 -> V_17 , V_44 , V_46 ) ) {
F_33 ( L_9
L_10
L_11
L_12
L_13 ,
V_10 -> V_14 , V_44 , V_46 ,
V_45 , V_48 ? 'u' : 'w' ,
V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
}
goto V_27;
}
if ( V_16 -> V_17 < V_44 ||
F_11 ( V_16 ) != V_45 + V_16 -> V_17 - V_44 ) {
F_33 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_44 , V_46 , V_45 ,
V_48 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_49 ? 'u' : 'w' ) ;
goto V_27;
}
if ( V_48 ^ V_49 ) {
F_33 ( L_14
L_15
L_16 , V_10 -> V_14 ,
V_44 , V_46 , V_45 ,
V_48 ? 'u' : 'w' , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , V_49 ? 'u' : 'w' ) ;
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
F_50 ( V_41 ) ;
F_51 ( V_41 ) ;
}
static void F_52 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
struct V_52 V_53 ;
int V_54 ;
V_53 . V_55 = V_16 -> V_17 ;
V_53 . V_56 = V_16 -> V_18 ;
V_54 = F_53 ( NULL , V_10 , & V_53 , 0 ) ;
if ( V_54 > 0 ) {
if ( F_22 ( V_16 ) || F_37 ( V_16 ) ) {
F_33 ( L_14
L_19
L_20 ,
V_10 -> V_14 , V_16 -> V_17 , V_16 -> V_18 ,
F_11 ( V_16 ) , F_12 ( V_16 ) ) ;
return;
} else if ( F_35 ( V_16 ) ) {
if ( V_54 != V_16 -> V_18 ) {
F_33 ( L_9
L_21 ,
V_10 -> V_14 , V_54 , V_16 -> V_18 ) ;
return;
}
if ( V_53 . V_57 != F_11 ( V_16 ) ) {
F_33 ( L_9
L_22
L_23 ,
V_10 -> V_14 , V_53 . V_57 ,
F_11 ( V_16 ) ) ;
return;
}
} else {
F_15 ( 1 ) ;
}
} else if ( V_54 == 0 ) {
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
F_15 ( ! F_55 ( & F_8 ( V_10 ) -> V_58 ) ) ;
if ( F_56 ( V_10 , V_59 ) )
F_42 ( V_10 , V_16 ) ;
else
F_52 ( V_10 , V_16 ) ;
}
static inline void F_54 ( struct V_10 * V_10 ,
struct V_2 * V_16 )
{
}
static int F_57 ( struct V_10 * V_10 , struct V_2 * V_60 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * * V_61 = & V_6 -> V_7 . V_11 ;
struct V_11 * V_62 = NULL ;
struct V_2 * V_16 ;
while ( * V_61 ) {
V_62 = * V_61 ;
V_16 = F_10 ( V_62 , struct V_2 , V_11 ) ;
if ( V_60 -> V_17 < V_16 -> V_17 ) {
if ( F_32 ( V_60 , V_16 ) ) {
V_16 -> V_17 = V_60 -> V_17 ;
V_16 -> V_18 += V_60 -> V_18 ;
if ( F_35 ( V_16 ) ||
F_36 ( V_16 ) )
F_58 ( V_16 ,
V_60 -> V_26 ) ;
V_16 = F_38 ( V_10 , V_16 ) ;
goto V_27;
}
V_61 = & ( * V_61 ) -> V_21 ;
} else if ( V_60 -> V_17 > F_14 ( V_16 ) ) {
if ( F_32 ( V_16 , V_60 ) ) {
V_16 -> V_18 += V_60 -> V_18 ;
V_16 = F_41 ( V_10 , V_16 ) ;
goto V_27;
}
V_61 = & ( * V_61 ) -> V_22 ;
} else {
F_15 ( 1 ) ;
return - V_63 ;
}
}
V_16 = F_25 ( V_10 , V_60 -> V_17 , V_60 -> V_18 ,
V_60 -> V_26 ) ;
if ( ! V_16 )
return - V_4 ;
F_59 ( & V_16 -> V_11 , V_62 , V_61 ) ;
F_60 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
V_27:
V_6 -> V_9 = V_16 ;
return 0 ;
}
int F_61 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_64 )
{
struct V_2 V_60 ;
T_2 V_23 = V_20 + V_28 - 1 ;
int V_65 = 0 ;
F_21 ( L_26 ,
V_20 , V_28 , V_29 , V_64 , V_10 -> V_14 ) ;
if ( ! V_28 )
return 0 ;
F_15 ( V_23 < V_20 ) ;
V_60 . V_17 = V_20 ;
V_60 . V_18 = V_28 ;
F_62 ( & V_60 , V_29 , V_64 ) ;
F_63 ( V_10 , & V_60 ) ;
F_54 ( V_10 , & V_60 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_65 = F_65 ( V_10 , V_20 , V_23 ) ;
if ( V_65 != 0 )
goto error;
V_66:
V_65 = F_57 ( V_10 , & V_60 ) ;
if ( V_65 == - V_4 && F_66 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_66;
if ( V_65 == - V_4 && ! F_22 ( & V_60 ) )
V_65 = 0 ;
error:
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_65 ;
}
void F_68 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 , T_3 V_29 ,
unsigned int V_64 )
{
struct V_2 * V_16 ;
struct V_2 V_60 ;
T_2 V_23 = V_20 + V_28 - 1 ;
V_60 . V_17 = V_20 ;
V_60 . V_18 = V_28 ;
F_62 ( & V_60 , V_29 , V_64 ) ;
F_69 ( V_10 , & V_60 ) ;
if ( ! V_28 )
return;
F_15 ( V_23 < V_20 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_16 = F_16 ( & F_8 ( V_10 ) -> V_15 . V_7 , V_20 ) ;
if ( ! V_16 || V_16 -> V_17 > V_23 )
F_57 ( V_10 , & V_60 ) ;
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
}
int F_70 ( struct V_10 * V_10 , T_2 V_20 ,
struct V_2 * V_16 )
{
struct V_5 * V_6 ;
struct V_67 * V_68 ;
struct V_2 * V_24 = NULL ;
struct V_11 * V_12 ;
int V_69 = 0 ;
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
V_69 = 1 ;
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
V_69 = 1 ;
break;
}
}
V_27:
V_68 = & F_28 ( V_10 -> V_32 ) -> V_33 ;
if ( V_69 ) {
F_15 ( ! V_24 ) ;
V_16 -> V_17 = V_24 -> V_17 ;
V_16 -> V_18 = V_24 -> V_18 ;
V_16 -> V_26 = V_24 -> V_26 ;
V_68 -> V_70 ++ ;
} else {
V_68 -> V_71 ++ ;
}
F_23 ( & F_8 ( V_10 ) -> V_25 ) ;
F_72 ( V_10 , V_16 , V_69 ) ;
return V_69 ;
}
static int F_65 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_23 )
{
struct V_5 * V_6 = & F_8 ( V_10 ) -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
struct V_2 V_72 ;
T_2 V_73 , V_74 ;
T_3 V_75 ;
int V_65 ;
V_66:
V_65 = 0 ;
V_16 = F_16 ( & V_6 -> V_7 , V_20 ) ;
if ( ! V_16 )
goto V_27;
if ( V_16 -> V_17 > V_23 )
goto V_27;
V_6 -> V_9 = NULL ;
V_72 . V_17 = V_16 -> V_17 ;
V_72 . V_18 = V_16 -> V_18 ;
V_72 . V_26 = V_16 -> V_26 ;
V_73 = V_20 > V_16 -> V_17 ? V_20 - V_16 -> V_17 : 0 ;
V_74 = F_14 ( V_16 ) > V_23 ? F_14 ( V_16 ) - V_23 : 0 ;
if ( V_73 > 0 )
V_16 -> V_18 = V_73 ;
if ( V_74 > 0 ) {
if ( V_73 > 0 ) {
struct V_2 V_60 ;
V_60 . V_17 = V_23 + 1 ;
V_60 . V_18 = V_74 ;
V_75 = 0x7FDEADBEEFULL ;
if ( F_35 ( & V_72 ) ||
F_36 ( & V_72 ) )
V_75 = F_11 ( & V_72 ) +
V_72 . V_18 - V_74 ;
F_62 ( & V_60 , V_75 ,
F_12 ( & V_72 ) ) ;
V_65 = F_57 ( V_10 , & V_60 ) ;
if ( V_65 ) {
V_16 -> V_17 = V_72 . V_17 ;
V_16 -> V_18 = V_72 . V_18 ;
if ( ( V_65 == - V_4 ) &&
F_66 ( F_28 ( V_10 -> V_32 ) , 1 ,
F_8 ( V_10 ) ) )
goto V_66;
goto V_27;
}
} else {
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_74 ;
if ( F_35 ( V_16 ) ||
F_36 ( V_16 ) ) {
V_75 = V_72 . V_26 + V_72 . V_18 - V_74 ;
F_58 ( V_16 , V_75 ) ;
}
}
goto V_27;
}
if ( V_73 > 0 ) {
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
T_2 V_76 = V_16 -> V_18 ;
V_73 = F_14 ( V_16 ) - V_23 ;
V_16 -> V_17 = V_23 + 1 ;
V_16 -> V_18 = V_73 ;
if ( F_35 ( V_16 ) || F_36 ( V_16 ) ) {
V_75 = V_16 -> V_26 + V_76 - V_73 ;
F_58 ( V_16 , V_75 ) ;
}
}
V_27:
return V_65 ;
}
int F_73 ( struct V_10 * V_10 , T_2 V_20 ,
T_2 V_28 )
{
T_2 V_23 ;
int V_65 = 0 ;
F_74 ( V_10 , V_20 , V_28 ) ;
F_21 ( L_29 ,
V_20 , V_28 , V_10 -> V_14 ) ;
if ( ! V_28 )
return V_65 ;
V_23 = V_20 + V_28 - 1 ;
F_15 ( V_23 < V_20 ) ;
F_64 ( & F_8 ( V_10 ) -> V_25 ) ;
V_65 = F_65 ( V_10 , V_20 , V_23 ) ;
F_67 ( & F_8 ( V_10 ) -> V_25 ) ;
F_6 ( V_10 ) ;
return V_65 ;
}
static int F_75 ( void * V_77 , struct V_78 * V_79 ,
struct V_78 * V_80 )
{
struct V_81 * V_82 , * V_83 ;
V_82 = F_76 ( V_79 , struct V_81 , V_84 ) ;
V_83 = F_76 ( V_80 , struct V_81 , V_84 ) ;
if ( F_77 ( & V_82 -> V_85 , V_86 ) &&
! F_77 ( & V_83 -> V_85 , V_86 ) )
return 1 ;
if ( ! F_77 ( & V_82 -> V_85 , V_86 ) &&
F_77 ( & V_83 -> V_85 , V_86 ) )
return - 1 ;
if ( V_82 -> V_87 == V_83 -> V_87 )
return 0 ;
if ( F_78 ( V_82 -> V_87 , V_83 -> V_87 ) )
return 1 ;
else
return - 1 ;
}
static int F_66 ( struct V_88 * V_89 , int V_90 ,
struct V_81 * V_91 )
{
struct V_81 * V_92 ;
struct V_67 * V_93 ;
struct V_78 * V_94 , * V_95 ;
F_79 ( V_96 ) ;
T_4 V_97 ;
T_5 V_98 ;
int V_99 = 0 ;
int V_100 = 0 , V_101 = 1 , V_102 = 0 ;
V_93 = & V_89 -> V_33 ;
V_97 = F_80 () ;
F_81 ( & V_89 -> V_103 ) ;
V_66:
F_82 (cur, tmp, &sbi->s_es_lru) {
int V_104 ;
if ( F_83 (
& V_93 -> V_34 ) == 0 )
break;
V_92 = F_76 ( V_94 , struct V_81 , V_84 ) ;
if ( ( V_93 -> V_105 < V_92 -> V_87 ) ||
( V_101 && F_77 ( & V_92 -> V_85 ,
V_86 ) ) ) {
V_102 ++ ;
F_84 ( V_94 , & V_96 ) ;
continue;
}
if ( V_92 -> V_31 == 0 || V_92 == V_91 ||
! F_85 ( & V_92 -> V_25 ) )
continue;
V_104 = F_86 ( V_92 , V_90 ) ;
if ( V_92 -> V_31 == 0 )
F_87 ( & V_92 -> V_84 ) ;
F_67 ( & V_92 -> V_25 ) ;
V_99 += V_104 ;
V_90 -= V_104 ;
if ( V_90 == 0 )
break;
}
F_88 ( & V_96 , & V_89 -> V_106 ) ;
F_89 ( & V_96 ) ;
if ( ( V_99 == 0 ) && V_102 && ! V_100 ) {
V_100 ++ ;
F_90 ( NULL , & V_89 -> V_106 , F_75 ) ;
V_93 -> V_105 = V_107 ;
V_92 = F_91 ( & V_89 -> V_106 , struct V_81 ,
V_84 ) ;
if ( F_77 ( & V_92 -> V_85 ,
V_86 ) )
V_101 = 0 ;
goto V_66;
}
F_92 ( & V_89 -> V_103 ) ;
if ( V_91 && V_99 == 0 )
V_99 = F_86 ( V_91 , V_90 ) ;
V_98 = F_93 ( F_94 ( F_80 () , V_97 ) ) ;
if ( F_95 ( V_93 -> V_108 ) )
V_93 -> V_108 = ( V_98 +
V_93 -> V_108 * 3 ) / 4 ;
else
V_93 -> V_108 = V_98 ;
if ( V_98 > V_93 -> V_109 )
V_93 -> V_109 = V_98 ;
if ( F_95 ( V_93 -> V_110 ) )
V_93 -> V_110 = ( V_99 +
V_93 -> V_110 * 3 ) / 4 ;
else
V_93 -> V_110 = V_99 ;
F_96 ( V_89 -> V_111 , V_99 , V_98 , V_101 ,
V_102 , V_100 ) ;
return V_99 ;
}
static unsigned long F_97 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
unsigned long V_116 ;
struct V_88 * V_89 ;
V_89 = F_98 ( V_113 , struct V_88 , V_117 ) ;
V_116 = F_83 ( & V_89 -> V_33 . V_34 ) ;
F_99 ( V_89 -> V_111 , V_115 -> V_90 , V_116 ) ;
return V_116 ;
}
static unsigned long F_100 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_88 * V_89 = F_98 ( V_113 ,
struct V_88 , V_117 ) ;
int V_90 = V_115 -> V_90 ;
int V_118 , V_99 ;
V_118 = F_83 ( & V_89 -> V_33 . V_34 ) ;
F_101 ( V_89 -> V_111 , V_90 , V_118 ) ;
if ( ! V_90 )
return V_118 ;
V_99 = F_66 ( V_89 , V_90 , NULL ) ;
F_102 ( V_89 -> V_111 , V_99 , V_118 ) ;
return V_99 ;
}
static void * F_103 ( struct V_119 * V_120 , T_6 * V_121 )
{
return * V_121 ? NULL : V_122 ;
}
static void *
F_104 ( struct V_119 * V_120 , void * V_123 , T_6 * V_121 )
{
return NULL ;
}
static int F_105 ( struct V_119 * V_120 , void * V_123 )
{
struct V_88 * V_89 = V_120 -> V_124 ;
struct V_67 * V_93 = & V_89 -> V_33 ;
struct V_81 * V_92 , * V_125 = NULL ;
unsigned int V_126 = 0 ;
if ( V_123 != V_122 )
return 0 ;
F_81 ( & V_89 -> V_103 ) ;
F_106 (ei, &sbi->s_es_lru, i_es_lru) {
V_126 ++ ;
if ( V_125 && V_125 -> V_35 < V_92 -> V_35 )
V_125 = V_92 ;
else if ( ! V_125 )
V_125 = V_92 ;
}
F_92 ( & V_89 -> V_103 ) ;
F_107 ( V_120 , L_30 ,
F_108 ( & V_93 -> V_36 ) ,
F_108 ( & V_93 -> V_34 ) ) ;
F_107 ( V_120 , L_31 ,
V_93 -> V_70 ,
V_93 -> V_71 ) ;
if ( V_93 -> V_105 != 0 )
F_107 ( V_120 , L_32 ,
F_109 ( V_107 -
V_93 -> V_105 ) ) ;
if ( V_126 )
F_107 ( V_120 , L_33 , V_126 ) ;
F_107 ( V_120 , L_34 ,
F_110 ( V_93 -> V_108 , 1000 ) ) ;
F_107 ( V_120 , L_35 , V_93 -> V_110 ) ;
if ( V_126 )
F_107 ( V_120 ,
L_36
L_37 ,
V_125 -> V_85 . V_14 , V_125 -> V_35 , V_125 -> V_31 ,
F_110 ( V_93 -> V_109 , 1000 ) ) ;
return 0 ;
}
static void F_111 ( struct V_119 * V_120 , void * V_123 )
{
}
static int
F_112 ( struct V_10 * V_10 , struct V_127 * V_127 )
{
int V_118 ;
V_118 = F_113 ( V_127 , & V_128 ) ;
if ( ! V_118 ) {
struct V_119 * V_129 = V_127 -> V_130 ;
V_129 -> V_124 = F_114 ( V_10 ) ;
}
return V_118 ;
}
static int
F_115 ( struct V_10 * V_10 , struct V_127 * V_127 )
{
return F_116 ( V_10 , V_127 ) ;
}
int F_117 ( struct V_88 * V_89 )
{
int V_65 ;
F_89 ( & V_89 -> V_106 ) ;
F_118 ( & V_89 -> V_103 ) ;
V_89 -> V_33 . V_105 = 0 ;
V_89 -> V_33 . V_110 = 0 ;
V_89 -> V_33 . V_70 = 0 ;
V_89 -> V_33 . V_71 = 0 ;
V_89 -> V_33 . V_108 = 0 ;
V_89 -> V_33 . V_109 = 0 ;
V_65 = F_119 ( & V_89 -> V_33 . V_36 , 0 , V_131 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_119 ( & V_89 -> V_33 . V_34 , 0 , V_131 ) ;
if ( V_65 )
goto V_132;
V_89 -> V_117 . V_133 = F_100 ;
V_89 -> V_117 . V_134 = F_97 ;
V_89 -> V_117 . V_135 = V_136 ;
V_65 = F_120 ( & V_89 -> V_117 ) ;
if ( V_65 )
goto V_137;
if ( V_89 -> V_138 )
F_121 ( L_38 , V_139 , V_89 -> V_138 ,
& V_140 , V_89 ) ;
return 0 ;
V_137:
F_122 ( & V_89 -> V_33 . V_34 ) ;
V_132:
F_122 ( & V_89 -> V_33 . V_36 ) ;
return V_65 ;
}
void F_123 ( struct V_88 * V_89 )
{
if ( V_89 -> V_138 )
F_124 ( L_38 , V_89 -> V_138 ) ;
F_122 ( & V_89 -> V_33 . V_36 ) ;
F_122 ( & V_89 -> V_33 . V_34 ) ;
F_125 ( & V_89 -> V_117 ) ;
}
void F_126 ( struct V_10 * V_10 )
{
struct V_81 * V_92 = F_8 ( V_10 ) ;
struct V_88 * V_89 = F_28 ( V_10 -> V_32 ) ;
V_92 -> V_87 = V_107 ;
if ( ! F_127 ( & V_92 -> V_84 ) )
return;
F_81 ( & V_89 -> V_103 ) ;
if ( F_127 ( & V_92 -> V_84 ) )
F_128 ( & V_92 -> V_84 , & V_89 -> V_106 ) ;
F_92 ( & V_89 -> V_103 ) ;
}
void F_129 ( struct V_10 * V_10 )
{
struct V_81 * V_92 = F_8 ( V_10 ) ;
struct V_88 * V_89 = F_28 ( V_10 -> V_32 ) ;
F_81 ( & V_89 -> V_103 ) ;
if ( ! F_127 ( & V_92 -> V_84 ) )
F_87 ( & V_92 -> V_84 ) ;
F_92 ( & V_89 -> V_103 ) ;
}
static int F_86 ( struct V_81 * V_92 ,
int V_90 )
{
struct V_10 * V_10 = & V_92 -> V_85 ;
struct V_5 * V_6 = & V_92 -> V_15 ;
struct V_11 * V_12 ;
struct V_2 * V_16 ;
unsigned long V_99 = 0 ;
static F_130 ( V_141 , V_142 ,
V_143 ) ;
if ( V_92 -> V_31 == 0 )
return 0 ;
if ( F_77 ( V_10 , V_86 ) &&
F_131 ( & V_141 ) )
F_132 ( V_10 -> V_32 , L_39 ) ;
V_12 = F_9 ( & V_6 -> V_7 ) ;
while ( V_12 != NULL ) {
V_16 = F_10 ( V_12 , struct V_2 , V_11 ) ;
V_12 = F_13 ( & V_16 -> V_11 ) ;
if ( ! F_22 ( V_16 ) ) {
F_40 ( & V_16 -> V_11 , & V_6 -> V_7 ) ;
F_29 ( V_10 , V_16 ) ;
V_99 ++ ;
if ( -- V_90 == 0 )
break;
}
}
V_6 -> V_9 = NULL ;
return V_99 ;
}
