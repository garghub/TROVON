unsigned long F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
unsigned long V_4 = 0 ;
struct V_5 * V_6 ;
F_2 () ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
V_3 = V_8 [ V_1 ] ;
V_6 = F_3 ( V_9 [ V_1 ] ) ;
if ( ! V_3 || ! V_6 )
continue;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_4 += V_6 [ V_2 ] . V_10 ;
}
F_4 () ;
return V_4 ;
}
void F_5 ( void )
{
F_6 ( L_1 , F_1 () ) ;
F_6 ( L_2 ,
V_11 . V_12 , V_11 . V_13 ,
V_11 . V_14 , V_11 . V_15 ) ;
F_6 ( L_3 ,
F_7 () << ( V_16 - 10 ) ) ;
F_6 ( L_4 , V_17 << ( V_16 - 10 ) ) ;
}
int F_8 ( struct V_18 * V_18 , T_1 V_19 )
{
int error ;
struct V_5 * V_5 ;
F_9 ( ! F_10 ( V_18 ) , V_18 ) ;
F_9 ( F_11 ( V_18 ) , V_18 ) ;
F_9 ( ! F_12 ( V_18 ) , V_18 ) ;
F_13 ( V_18 ) ;
F_14 ( V_18 ) ;
F_15 ( V_18 , V_19 . V_20 ) ;
V_5 = F_16 ( V_19 ) ;
F_17 ( & V_5 -> V_21 ) ;
error = F_18 ( & V_5 -> V_22 ,
F_19 ( V_19 ) , V_18 ) ;
if ( F_20 ( ! error ) ) {
V_5 -> V_10 ++ ;
F_21 ( V_18 , V_23 ) ;
F_22 ( V_12 ) ;
}
F_23 ( & V_5 -> V_21 ) ;
if ( F_24 ( error ) ) {
F_25 ( error == - V_24 ) ;
F_15 ( V_18 , 0UL ) ;
F_26 ( V_18 ) ;
F_27 ( V_18 ) ;
}
return error ;
}
int F_28 ( struct V_18 * V_18 , T_1 V_19 , T_2 V_25 )
{
int error ;
error = F_29 ( V_25 ) ;
if ( ! error ) {
error = F_8 ( V_18 , V_19 ) ;
F_30 () ;
}
return error ;
}
void F_31 ( struct V_18 * V_18 )
{
T_1 V_19 ;
struct V_5 * V_5 ;
F_9 ( ! F_10 ( V_18 ) , V_18 ) ;
F_9 ( ! F_11 ( V_18 ) , V_18 ) ;
F_9 ( F_32 ( V_18 ) , V_18 ) ;
V_19 . V_20 = F_33 ( V_18 ) ;
V_5 = F_16 ( V_19 ) ;
F_34 ( & V_5 -> V_22 , F_19 ( V_19 ) ) ;
F_15 ( V_18 , 0 ) ;
F_26 ( V_18 ) ;
V_5 -> V_10 -- ;
F_35 ( V_18 , V_23 ) ;
F_22 ( V_13 ) ;
}
int F_36 ( struct V_18 * V_18 , struct V_26 * V_27 )
{
T_1 V_19 ;
int V_28 ;
F_9 ( ! F_10 ( V_18 ) , V_18 ) ;
F_9 ( ! F_37 ( V_18 ) , V_18 ) ;
V_19 = F_38 () ;
if ( ! V_19 . V_20 )
return 0 ;
if ( F_39 ( V_18 , V_19 ) ) {
F_40 ( V_19 ) ;
return 0 ;
}
if ( F_24 ( F_41 ( V_18 ) ) )
if ( F_24 ( F_42 ( V_18 , V_27 ) ) ) {
F_40 ( V_19 ) ;
return 0 ;
}
V_28 = F_28 ( V_18 , V_19 ,
V_29 | V_30 | V_31 ) ;
if ( ! V_28 ) {
return 1 ;
} else {
F_40 ( V_19 ) ;
return 0 ;
}
}
void F_43 ( struct V_18 * V_18 )
{
T_1 V_19 ;
struct V_5 * V_5 ;
V_19 . V_20 = F_33 ( V_18 ) ;
V_5 = F_16 ( V_19 ) ;
F_17 ( & V_5 -> V_21 ) ;
F_31 ( V_18 ) ;
F_23 ( & V_5 -> V_21 ) ;
F_40 ( V_19 ) ;
F_27 ( V_18 ) ;
}
static inline void F_44 ( struct V_18 * V_18 )
{
if ( F_11 ( V_18 ) && ! F_45 ( V_18 ) && F_46 ( V_18 ) ) {
F_47 ( V_18 ) ;
F_48 ( V_18 ) ;
}
}
void F_49 ( struct V_18 * V_18 )
{
F_44 ( V_18 ) ;
if ( ! F_50 ( V_18 ) )
F_27 ( V_18 ) ;
}
void F_51 ( struct V_18 * * V_32 , int V_3 )
{
struct V_18 * * V_33 = V_32 ;
int V_1 ;
F_52 () ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
F_44 ( V_33 [ V_1 ] ) ;
F_53 ( V_33 , V_3 , false ) ;
}
struct V_18 * F_54 ( T_1 V_19 )
{
struct V_18 * V_18 ;
V_18 = F_55 ( F_16 ( V_19 ) , F_19 ( V_19 ) ) ;
if ( V_18 ) {
F_22 ( V_14 ) ;
if ( F_56 ( V_18 ) )
F_57 ( & V_34 ) ;
}
F_22 ( V_15 ) ;
return V_18 ;
}
struct V_18 * F_58 ( T_1 V_19 , T_2 V_25 ,
struct V_35 * V_36 , unsigned long V_37 ,
bool * V_38 )
{
struct V_18 * V_39 , * V_40 = NULL ;
struct V_5 * V_41 = F_16 ( V_19 ) ;
int V_28 ;
* V_38 = false ;
do {
V_39 = F_55 ( V_41 , F_19 ( V_19 ) ) ;
if ( V_39 )
break;
if ( ! F_59 ( V_19 ) && V_42 )
break;
if ( ! V_40 ) {
V_40 = F_60 ( V_25 , V_36 , V_37 ) ;
if ( ! V_40 )
break;
}
V_28 = F_29 ( V_25 & V_43 ) ;
if ( V_28 )
break;
V_28 = F_61 ( V_19 ) ;
if ( V_28 == - V_24 ) {
F_30 () ;
F_62 () ;
continue;
}
if ( V_28 ) {
F_30 () ;
break;
}
F_63 ( V_40 ) ;
F_64 ( V_40 ) ;
V_28 = F_8 ( V_40 , V_19 ) ;
if ( F_20 ( ! V_28 ) ) {
F_30 () ;
F_65 ( V_40 ) ;
* V_38 = true ;
return V_40 ;
}
F_30 () ;
F_66 ( V_40 ) ;
F_40 ( V_19 ) ;
} while ( V_28 != - V_44 );
if ( V_40 )
F_27 ( V_40 ) ;
return V_39 ;
}
struct V_18 * F_67 ( T_1 V_19 , T_2 V_25 ,
struct V_35 * V_36 , unsigned long V_37 )
{
bool V_45 ;
struct V_18 * V_46 = F_58 ( V_19 , V_25 ,
V_36 , V_37 , & V_45 ) ;
if ( V_45 )
F_68 ( V_46 ) ;
return V_46 ;
}
static unsigned long F_69 ( unsigned long V_47 )
{
static unsigned long V_48 ;
unsigned int V_32 , V_49 , V_50 ;
static T_3 V_51 ;
V_49 = 1 << F_70 ( V_52 ) ;
if ( V_49 <= 1 )
return 1 ;
V_32 = F_71 ( & V_34 , 0 ) + 2 ;
if ( V_32 == 2 ) {
if ( V_47 != V_48 + 1 && V_47 != V_48 - 1 )
V_32 = 1 ;
V_48 = V_47 ;
} else {
unsigned int V_53 = 4 ;
while ( V_53 < V_32 )
V_53 <<= 1 ;
V_32 = V_53 ;
}
if ( V_32 > V_49 )
V_32 = V_49 ;
V_50 = F_72 ( & V_51 ) / 2 ;
if ( V_32 < V_50 )
V_32 = V_50 ;
F_73 ( & V_51 , V_32 ) ;
return V_32 ;
}
struct V_18 * F_74 ( T_1 V_19 , T_2 V_25 ,
struct V_35 * V_36 , unsigned long V_37 )
{
struct V_18 * V_18 ;
unsigned long V_54 = F_19 ( V_19 ) ;
unsigned long V_47 = V_54 ;
unsigned long V_55 , V_56 ;
unsigned long V_57 ;
struct V_58 V_59 ;
V_57 = F_69 ( V_47 ) - 1 ;
if ( ! V_57 )
goto V_60;
V_55 = V_47 & ~ V_57 ;
V_56 = V_47 | V_57 ;
if ( ! V_55 )
V_55 ++ ;
F_75 ( & V_59 ) ;
for ( V_47 = V_55 ; V_47 <= V_56 ; V_47 ++ ) {
V_18 = F_67 ( F_76 ( F_77 ( V_19 ) , V_47 ) ,
V_25 , V_36 , V_37 ) ;
if ( ! V_18 )
continue;
if ( V_47 != V_54 )
F_78 ( V_18 ) ;
F_27 ( V_18 ) ;
}
F_79 ( & V_59 ) ;
F_52 () ;
V_60:
return F_67 ( V_19 , V_25 , V_36 , V_37 ) ;
}
int F_80 ( unsigned int type , unsigned long V_61 )
{
struct V_5 * V_6 , * V_62 ;
unsigned int V_1 , V_3 ;
V_3 = F_81 ( V_61 , V_63 ) ;
V_6 = F_82 ( sizeof( struct V_5 ) * V_3 ) ;
if ( ! V_6 )
return - V_44 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
V_62 = V_6 + V_1 ;
F_83 ( & V_62 -> V_22 , V_64 | V_31 ) ;
F_73 ( & V_62 -> V_65 , 0 ) ;
V_62 -> V_66 = & V_67 ;
F_84 ( V_62 ) ;
F_85 ( & V_62 -> V_21 ) ;
}
V_8 [ type ] = V_3 ;
F_86 ( V_9 [ type ] , V_6 ) ;
return 0 ;
}
void F_87 ( unsigned int type )
{
struct V_5 * V_6 ;
V_6 = V_9 [ type ] ;
V_8 [ type ] = 0 ;
F_86 ( V_9 [ type ] , NULL ) ;
F_88 () ;
F_89 ( V_6 ) ;
}
