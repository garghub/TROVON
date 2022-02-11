int F_1 ( void )
{
return V_1 ;
}
static int F_2 ( struct V_2 * V_3 )
{
int V_4 ;
unsigned long V_5 ;
F_3 ( & V_6 , V_5 ) ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ! V_8 [ V_4 ] ) {
V_8 [ V_4 ] = V_3 ;
V_3 -> V_9 = V_4 ;
V_1 ++ ;
F_4 ( & V_6 , V_5 ) ;
return V_4 ;
}
}
F_4 ( & V_6 , V_5 ) ;
return - 1 ;
}
static struct V_2 * F_5 ( int V_10 , int V_11 )
{
struct V_2 * V_3 ;
unsigned long V_5 ;
F_3 ( & V_6 , V_5 ) ;
V_3 = V_8 [ V_10 ] ;
if ( V_3 ) {
F_6 ( & V_3 -> V_12 ) ;
if ( V_3 -> V_13 == V_11 ) {
V_3 -> V_14 = 1 ;
F_7 ( & V_3 -> V_12 ) ;
V_8 [ V_10 ] = NULL ;
V_1 -- ;
F_4 ( & V_6 , V_5 ) ;
return V_3 ;
}
F_7 ( & V_3 -> V_12 ) ;
}
F_4 ( & V_6 , V_5 ) ;
return NULL ;
}
static struct V_2 * F_8 ( int V_13 , int V_15 )
{
struct V_2 * V_3 ;
V_3 = F_9 ( sizeof( * V_3 ) , V_16 ) ;
if ( ! V_3 )
return NULL ;
F_10 ( & V_3 -> V_12 ) ;
F_10 ( & V_3 -> V_17 ) ;
F_11 ( & V_3 -> V_18 ) ;
F_12 ( & V_3 -> V_19 ) ;
V_3 -> V_9 = - 1 ;
V_3 -> V_20 = F_13 () ;
V_3 -> V_21 = F_13 () ;
V_3 -> V_22 = F_14 () ;
if ( V_3 -> V_20 == NULL || V_3 -> V_21 == NULL || V_3 -> V_22 == NULL ) {
F_15 ( & V_3 -> V_20 ) ;
F_15 ( & V_3 -> V_21 ) ;
F_16 ( & V_3 -> V_22 ) ;
F_17 ( V_3 ) ;
return NULL ;
}
V_3 -> V_13 = V_13 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_14 = 0 ;
return V_3 ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_19 ( & V_3 -> V_18 ) ;
F_20 ( V_3 -> V_22 ) ;
F_21 ( V_3 ) ;
F_22 ( & V_3 -> V_18 ) ;
F_23 ( & V_3 -> V_19 ) ;
F_15 ( & V_3 -> V_20 ) ;
F_15 ( & V_3 -> V_21 ) ;
F_16 ( & V_3 -> V_22 ) ;
F_17 ( V_3 ) ;
}
int T_1 F_24 ( void )
{
return 0 ;
}
void T_2 F_25 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( V_8 [ V_4 ] )
F_18 ( V_8 [ V_4 ] ) ;
}
}
int F_26 ( int V_11 , int V_15 , unsigned int V_23 )
{
struct V_2 * V_3 ;
V_3 = F_8 ( V_11 , V_15 ) ;
if ( V_3 == NULL )
return - V_24 ;
V_3 -> V_23 = V_23 ;
F_27 ( V_3 , V_11 , 1 ) ;
if ( F_2 ( V_3 ) < 0 ) {
F_18 ( V_3 ) ;
return - V_24 ;
}
return V_3 -> V_9 ;
}
int F_28 ( int V_11 , int V_25 )
{
struct V_2 * V_3 ;
if ( V_25 < 0 || V_25 >= V_7 )
return - V_26 ;
V_3 = F_5 ( V_25 , V_11 ) ;
if ( V_3 == NULL )
return - V_26 ;
F_18 ( V_3 ) ;
return 0 ;
}
struct V_2 * F_29 ( int V_25 )
{
struct V_2 * V_3 ;
unsigned long V_5 ;
if ( V_25 < 0 || V_25 >= V_7 )
return NULL ;
F_3 ( & V_6 , V_5 ) ;
V_3 = V_8 [ V_25 ] ;
if ( V_3 )
F_30 ( & V_3 -> V_19 ) ;
F_4 ( & V_6 , V_5 ) ;
return V_3 ;
}
struct V_2 * F_31 ( char * V_27 )
{
int V_4 ;
struct V_2 * V_3 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) != NULL ) {
if ( strncmp ( V_3 -> V_27 , V_27 , sizeof( V_3 -> V_27 ) ) == 0 )
return V_3 ;
F_32 ( V_3 ) ;
}
}
return NULL ;
}
void F_33 ( struct V_2 * V_3 , int V_28 , int V_29 )
{
unsigned long V_5 ;
struct V_30 * V_31 ;
if ( V_3 == NULL )
return;
F_3 ( & V_3 -> V_17 , V_5 ) ;
if ( V_3 -> V_32 ) {
V_3 -> V_33 = 1 ;
F_4 ( & V_3 -> V_17 , V_5 ) ;
return;
}
V_3 -> V_32 = 1 ;
F_4 ( & V_3 -> V_17 , V_5 ) ;
V_34:
while ( ( V_31 = F_34 ( V_3 -> V_20 ) ) != NULL ) {
if ( F_35 ( & V_3 -> V_22 -> V_35 . V_36 ,
& V_31 -> V_37 . time . V_35 ) ) {
V_31 = F_36 ( V_3 -> V_20 ) ;
if ( V_31 )
F_37 ( V_31 , V_28 , V_29 ) ;
} else {
break;
}
}
while ( ( V_31 = F_34 ( V_3 -> V_21 ) ) != NULL ) {
if ( F_38 ( & V_3 -> V_22 -> V_38 ,
& V_31 -> V_37 . time . time ) ) {
V_31 = F_36 ( V_3 -> V_21 ) ;
if ( V_31 )
F_37 ( V_31 , V_28 , V_29 ) ;
} else {
break;
}
}
F_3 ( & V_3 -> V_17 , V_5 ) ;
if ( V_3 -> V_33 ) {
V_3 -> V_33 = 0 ;
F_4 ( & V_3 -> V_17 , V_5 ) ;
goto V_34;
}
V_3 -> V_32 = 0 ;
F_4 ( & V_3 -> V_17 , V_5 ) ;
}
int F_39 ( struct V_30 * V_31 , int V_28 , int V_29 )
{
int V_39 , V_40 ;
struct V_2 * V_3 ;
if ( F_40 ( ! V_31 ) )
return - V_26 ;
V_39 = V_31 -> V_37 . V_9 ;
V_3 = F_29 ( V_39 ) ;
if ( V_3 == NULL )
return - V_26 ;
if ( ( V_31 -> V_37 . V_5 & V_41 ) == V_42 ) {
switch ( V_31 -> V_37 . V_5 & V_43 ) {
case V_44 :
V_31 -> V_37 . time . V_35 += V_3 -> V_22 -> V_35 . V_36 ;
break;
case V_45 :
F_41 ( & V_31 -> V_37 . time . time ,
& V_3 -> V_22 -> V_38 ) ;
break;
}
V_31 -> V_37 . V_5 &= ~ V_41 ;
V_31 -> V_37 . V_5 |= V_46 ;
}
switch ( V_31 -> V_37 . V_5 & V_43 ) {
case V_44 :
V_40 = F_42 ( V_3 -> V_20 , V_31 ) ;
break;
case V_45 :
default:
V_40 = F_42 ( V_3 -> V_21 , V_31 ) ;
break;
}
if ( V_40 < 0 ) {
F_32 ( V_3 ) ;
return V_40 ;
}
F_33 ( V_3 , V_28 , V_29 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
static inline int F_43 ( struct V_2 * V_3 , int V_11 )
{
return ( V_3 -> V_13 == V_11 ) || ( ! V_3 -> V_15 && ! V_3 -> V_14 ) ;
}
static int F_44 ( struct V_2 * V_3 , int V_11 )
{
unsigned long V_5 ;
int V_47 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
V_47 = F_43 ( V_3 , V_11 ) ;
if ( V_47 )
V_3 -> V_14 = 1 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
return V_47 ;
}
static inline void F_45 ( struct V_2 * V_3 )
{
unsigned long V_5 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
V_3 -> V_14 = 0 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
}
int F_46 ( int V_25 , int V_11 )
{
struct V_2 * V_3 = F_29 ( V_25 ) ;
int V_47 ;
unsigned long V_5 ;
if ( ! V_3 )
return 0 ;
F_3 ( & V_3 -> V_12 , V_5 ) ;
V_47 = F_43 ( V_3 , V_11 ) ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
F_32 ( V_3 ) ;
return V_47 ;
}
int F_47 ( int V_25 , int V_11 , int V_15 )
{
struct V_2 * V_3 = F_29 ( V_25 ) ;
if ( V_3 == NULL )
return - V_26 ;
if ( ! F_44 ( V_3 , V_11 ) ) {
F_32 ( V_3 ) ;
return - V_48 ;
}
V_3 -> V_15 = V_15 ? 1 : 0 ;
V_3 -> V_13 = V_11 ;
F_45 ( V_3 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
int F_48 ( int V_25 )
{
int V_49 = 0 ;
struct V_2 * V_9 ;
struct V_50 * V_51 ;
V_9 = F_29 ( V_25 ) ;
if ( V_9 == NULL )
return - V_26 ;
V_51 = V_9 -> V_22 ;
if ( ( V_49 = F_49 ( V_9 ) ) < 0 ) {
F_50 ( V_51 ) ;
V_49 = F_49 ( V_9 ) ;
}
F_32 ( V_9 ) ;
return V_49 ;
}
int F_51 ( int V_25 )
{
struct V_2 * V_9 ;
int V_49 = 0 ;
V_9 = F_29 ( V_25 ) ;
if ( V_9 == NULL )
return - V_26 ;
F_21 ( V_9 ) ;
F_32 ( V_9 ) ;
return V_49 ;
}
int F_52 ( int V_25 , int V_11 ,
struct V_52 * V_53 )
{
struct V_2 * V_3 = F_29 ( V_25 ) ;
int V_49 ;
if ( V_3 == NULL )
return - V_26 ;
if ( ! F_44 ( V_3 , V_11 ) ) {
F_32 ( V_3 ) ;
return - V_48 ;
}
V_49 = F_53 ( V_3 -> V_22 , V_53 -> V_54 ) ;
if ( V_49 >= 0 )
V_49 = F_54 ( V_3 -> V_22 , V_53 -> V_55 ) ;
if ( V_49 >= 0 && V_53 -> V_56 > 0 )
V_49 = F_55 ( V_3 -> V_22 , V_53 -> V_57 ,
V_53 -> V_56 ) ;
F_45 ( V_3 ) ;
F_32 ( V_3 ) ;
return V_49 ;
}
static void F_27 ( struct V_2 * V_9 , int V_11 , int V_58 )
{
if ( V_58 ) {
if ( ! F_56 ( V_11 , V_9 -> V_59 ) )
V_9 -> V_60 ++ ;
} else {
if ( F_57 ( V_11 , V_9 -> V_59 ) )
V_9 -> V_60 -- ;
}
if ( V_9 -> V_60 ) {
if ( V_58 && V_9 -> V_60 == 1 )
F_50 ( V_9 -> V_22 ) ;
F_49 ( V_9 ) ;
} else {
F_21 ( V_9 ) ;
}
}
int F_58 ( int V_25 , int V_11 , int V_58 )
{
struct V_2 * V_9 ;
V_9 = F_29 ( V_25 ) ;
if ( V_9 == NULL )
return - V_26 ;
F_19 ( & V_9 -> V_18 ) ;
F_27 ( V_9 , V_11 , V_58 ) ;
F_22 ( & V_9 -> V_18 ) ;
F_32 ( V_9 ) ;
return 0 ;
}
int F_59 ( int V_25 , int V_11 )
{
struct V_2 * V_3 ;
int V_49 ;
V_3 = F_29 ( V_25 ) ;
if ( V_3 == NULL )
return - V_26 ;
V_49 = F_60 ( V_11 , V_3 -> V_59 ) ? 1 : 0 ;
F_32 ( V_3 ) ;
return V_49 ;
}
void F_61 ( int V_11 )
{
unsigned long V_5 ;
int V_4 ;
struct V_2 * V_3 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) == NULL )
continue;
F_3 ( & V_3 -> V_12 , V_5 ) ;
if ( V_3 -> V_13 == V_11 )
V_3 -> V_14 = 1 ;
F_4 ( & V_3 -> V_12 , V_5 ) ;
if ( V_3 -> V_13 == V_11 ) {
if ( V_3 -> V_22 -> V_61 )
F_20 ( V_3 -> V_22 ) ;
F_62 ( V_3 -> V_22 ) ;
}
F_32 ( V_3 ) ;
}
}
void F_63 ( int V_11 )
{
int V_4 ;
struct V_2 * V_3 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_5 ( V_4 , V_11 ) ) != NULL )
F_18 ( V_3 ) ;
}
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) == NULL )
continue;
if ( F_60 ( V_11 , V_3 -> V_59 ) ) {
F_64 ( V_3 -> V_20 , V_11 , 0 ) ;
F_64 ( V_3 -> V_21 , V_11 , 0 ) ;
F_58 ( V_3 -> V_9 , V_11 , 0 ) ;
}
F_32 ( V_3 ) ;
}
}
void F_65 ( int V_11 )
{
int V_4 ;
struct V_2 * V_3 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) == NULL )
continue;
F_64 ( V_3 -> V_20 , V_11 , 0 ) ;
F_64 ( V_3 -> V_21 , V_11 , 0 ) ;
F_32 ( V_3 ) ;
}
}
void F_66 ( int V_11 , struct V_62 * V_53 )
{
int V_4 ;
struct V_2 * V_3 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) == NULL )
continue;
if ( F_60 ( V_11 , V_3 -> V_59 ) &&
( ! ( V_53 -> V_63 & V_64 ) ||
V_3 -> V_9 == V_53 -> V_9 ) ) {
F_67 ( V_3 -> V_20 , V_11 , V_53 ) ;
F_67 ( V_3 -> V_21 , V_11 , V_53 ) ;
}
F_32 ( V_3 ) ;
}
}
static void F_68 ( struct V_2 * V_3 , struct V_65 * V_66 ,
int V_28 , int V_29 )
{
struct V_65 V_67 ;
V_67 = * V_66 ;
V_67 . V_5 = V_44 | V_46 ;
V_67 . time . V_35 = V_3 -> V_22 -> V_35 . V_36 ;
V_67 . V_9 = V_3 -> V_9 ;
V_67 . V_68 . V_9 . V_9 = V_3 -> V_9 ;
V_67 . V_69 . V_11 = V_70 ;
V_67 . V_69 . V_71 = V_72 ;
V_67 . V_39 . V_11 = V_73 ;
F_69 ( V_70 , & V_67 , V_28 , V_29 ) ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_65 * V_66 ,
int V_28 , int V_29 )
{
switch ( V_66 -> type ) {
case V_74 :
F_64 ( V_3 -> V_20 , V_66 -> V_69 . V_11 , 1 ) ;
F_64 ( V_3 -> V_21 , V_66 -> V_69 . V_11 , 1 ) ;
if ( ! F_71 ( V_3 -> V_22 ) )
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
break;
case V_75 :
if ( ! F_72 ( V_3 -> V_22 ) )
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
break;
case V_76 :
F_20 ( V_3 -> V_22 ) ;
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
break;
case V_77 :
F_53 ( V_3 -> V_22 , V_66 -> V_68 . V_9 . V_78 . V_79 ) ;
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
break;
case V_80 :
if ( F_73 ( V_3 -> V_22 , V_66 -> V_68 . V_9 . V_78 . time . V_35 ) == 0 ) {
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
}
break;
case V_81 :
if ( F_74 ( V_3 -> V_22 , V_66 -> V_68 . V_9 . V_78 . time . time ) == 0 ) {
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
}
break;
case V_82 :
if ( F_55 ( V_3 -> V_22 ,
V_66 -> V_68 . V_9 . V_78 . V_83 . V_79 ,
V_66 -> V_68 . V_9 . V_78 . V_83 . V_84 ) == 0 ) {
F_68 ( V_3 , V_66 , V_28 , V_29 ) ;
}
break;
}
}
int F_75 ( struct V_65 * V_66 , int V_28 , int V_29 )
{
struct V_2 * V_3 ;
if ( F_40 ( ! V_66 ) )
return - V_26 ;
V_3 = F_29 ( V_66 -> V_68 . V_9 . V_9 ) ;
if ( V_3 == NULL )
return - V_26 ;
if ( ! F_44 ( V_3 , V_66 -> V_69 . V_11 ) ) {
F_32 ( V_3 ) ;
return - V_48 ;
}
F_70 ( V_3 , V_66 , V_28 , V_29 ) ;
F_45 ( V_3 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
void F_76 ( struct V_85 * V_86 ,
struct V_87 * V_88 )
{
int V_4 , V_89 ;
struct V_2 * V_3 ;
struct V_50 * V_51 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
if ( ( V_3 = F_29 ( V_4 ) ) == NULL )
continue;
V_51 = V_3 -> V_22 ;
if ( V_51 -> V_54 )
V_89 = 60000000 / V_51 -> V_54 ;
else
V_89 = 0 ;
F_77 ( V_88 , L_1 , V_3 -> V_9 , V_3 -> V_27 ) ;
F_77 ( V_88 , L_2 , V_3 -> V_13 ) ;
F_77 ( V_88 , L_3 , V_3 -> V_15 ? L_4 : L_5 ) ;
F_77 ( V_88 , L_6 , F_78 ( V_3 -> V_21 ) ) ;
F_77 ( V_88 , L_7 , F_78 ( V_3 -> V_20 ) ) ;
F_77 ( V_88 , L_8 , V_51 -> V_61 ? L_9 : L_10 ) ;
F_77 ( V_88 , L_11 , V_51 -> V_55 ) ;
F_77 ( V_88 , L_12 , V_51 -> V_54 ) ;
F_77 ( V_88 , L_13 , V_89 ) ;
F_77 ( V_88 , L_14 , V_51 -> V_38 . V_90 , V_51 -> V_38 . V_91 ) ;
F_77 ( V_88 , L_15 , V_51 -> V_35 . V_36 ) ;
F_77 ( V_88 , L_16 ) ;
F_32 ( V_3 ) ;
}
}
