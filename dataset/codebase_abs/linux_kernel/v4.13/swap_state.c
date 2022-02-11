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
int error , V_1 , V_3 = F_9 ( V_18 ) ;
struct V_5 * V_5 ;
T_2 V_20 = F_10 ( V_19 ) ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( F_13 ( V_18 ) , V_18 ) ;
F_11 ( ! F_14 ( V_18 ) , V_18 ) ;
F_15 ( V_18 , V_3 ) ;
F_16 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
F_18 ( & V_5 -> V_21 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_19 ( V_18 + V_1 , V_19 . V_22 + V_1 ) ;
error = F_20 ( & V_5 -> V_23 ,
V_20 + V_1 , V_18 + V_1 ) ;
if ( F_21 ( error ) )
break;
}
if ( F_22 ( ! error ) ) {
V_5 -> V_10 += V_3 ;
F_23 ( F_24 ( V_18 ) , V_24 , V_3 ) ;
F_25 ( V_12 , V_3 ) ;
} else {
F_26 ( error == - V_25 ) ;
F_19 ( V_18 + V_1 , 0UL ) ;
while ( V_1 -- ) {
F_27 ( & V_5 -> V_23 , V_20 + V_1 ) ;
F_19 ( V_18 + V_1 , 0UL ) ;
}
F_28 ( V_18 ) ;
F_29 ( V_18 , V_3 ) ;
}
F_30 ( & V_5 -> V_21 ) ;
return error ;
}
int F_31 ( struct V_18 * V_18 , T_1 V_19 , T_3 V_26 )
{
int error ;
error = F_32 ( V_26 , F_33 ( V_18 ) ) ;
if ( ! error ) {
error = F_8 ( V_18 , V_19 ) ;
F_34 () ;
}
return error ;
}
void F_35 ( struct V_18 * V_18 )
{
struct V_5 * V_5 ;
int V_1 , V_3 = F_9 ( V_18 ) ;
T_1 V_19 ;
T_2 V_20 ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( ! F_13 ( V_18 ) , V_18 ) ;
F_11 ( F_36 ( V_18 ) , V_18 ) ;
V_19 . V_22 = F_37 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
V_20 = F_10 ( V_19 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_27 ( & V_5 -> V_23 , V_20 + V_1 ) ;
F_19 ( V_18 + V_1 , 0 ) ;
}
F_28 ( V_18 ) ;
V_5 -> V_10 -= V_3 ;
F_23 ( F_24 ( V_18 ) , V_24 , - V_3 ) ;
F_25 ( V_13 , V_3 ) ;
}
int F_38 ( struct V_18 * V_18 )
{
T_1 V_19 ;
int V_27 ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( ! F_39 ( V_18 ) , V_18 ) ;
V_19 = F_40 ( V_18 ) ;
if ( ! V_19 . V_22 )
return 0 ;
if ( F_41 ( V_18 , V_19 ) )
goto V_28;
V_27 = F_31 ( V_18 , V_19 ,
V_29 | V_30 | V_31 ) ;
if ( V_27 )
goto V_28;
return 1 ;
V_28:
F_42 ( V_18 , V_19 ) ;
return 0 ;
}
void F_43 ( struct V_18 * V_18 )
{
T_1 V_19 ;
struct V_5 * V_5 ;
V_19 . V_22 = F_37 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
F_18 ( & V_5 -> V_21 ) ;
F_35 ( V_18 ) ;
F_30 ( & V_5 -> V_21 ) ;
F_42 ( V_18 , V_19 ) ;
F_29 ( V_18 , F_9 ( V_18 ) ) ;
}
static inline void F_44 ( struct V_18 * V_18 )
{
if ( F_13 ( V_18 ) && ! F_45 ( V_18 ) && F_46 ( V_18 ) ) {
F_47 ( V_18 ) ;
F_48 ( V_18 ) ;
}
}
void F_49 ( struct V_18 * V_18 )
{
F_44 ( V_18 ) ;
if ( ! F_50 ( V_18 ) )
F_51 ( V_18 ) ;
}
void F_52 ( struct V_18 * * V_32 , int V_3 )
{
struct V_18 * * V_33 = V_32 ;
int V_1 ;
F_53 () ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
F_44 ( V_33 [ V_1 ] ) ;
F_54 ( V_33 , V_3 , false ) ;
}
struct V_18 * F_55 ( T_1 V_19 )
{
struct V_18 * V_18 ;
V_18 = F_56 ( F_17 ( V_19 ) , F_10 ( V_19 ) ) ;
if ( V_18 && F_22 ( ! F_57 ( V_18 ) ) ) {
F_58 ( V_14 ) ;
if ( F_59 ( V_18 ) )
F_60 ( & V_34 ) ;
}
F_58 ( V_15 ) ;
return V_18 ;
}
struct V_18 * F_61 ( T_1 V_19 , T_3 V_26 ,
struct V_35 * V_36 , unsigned long V_37 ,
bool * V_38 )
{
struct V_18 * V_39 , * V_40 = NULL ;
struct V_5 * V_41 = F_17 ( V_19 ) ;
int V_27 ;
* V_38 = false ;
do {
V_39 = F_56 ( V_41 , F_10 ( V_19 ) ) ;
if ( V_39 )
break;
if ( ! F_62 ( V_19 ) && V_42 )
break;
if ( ! V_40 ) {
V_40 = F_63 ( V_26 , V_36 , V_37 ) ;
if ( ! V_40 )
break;
}
V_27 = F_64 ( V_26 & V_43 ) ;
if ( V_27 )
break;
V_27 = F_65 ( V_19 ) ;
if ( V_27 == - V_25 ) {
F_34 () ;
F_66 () ;
continue;
}
if ( V_27 ) {
F_34 () ;
break;
}
F_67 ( V_40 ) ;
F_68 ( V_40 ) ;
V_27 = F_8 ( V_40 , V_19 ) ;
if ( F_22 ( ! V_27 ) ) {
F_34 () ;
F_69 ( V_40 ) ;
* V_38 = true ;
return V_40 ;
}
F_34 () ;
F_70 ( V_40 ) ;
F_42 ( V_40 , V_19 ) ;
} while ( V_27 != - V_44 );
if ( V_40 )
F_51 ( V_40 ) ;
return V_39 ;
}
struct V_18 * F_71 ( T_1 V_19 , T_3 V_26 ,
struct V_35 * V_36 , unsigned long V_37 , bool V_45 )
{
bool V_46 ;
struct V_18 * V_47 = F_61 ( V_19 , V_26 ,
V_36 , V_37 , & V_46 ) ;
if ( V_46 )
F_72 ( V_47 , V_45 ) ;
return V_47 ;
}
static unsigned long F_73 ( unsigned long V_48 )
{
static unsigned long V_49 ;
unsigned int V_32 , V_50 , V_51 ;
static T_4 V_52 ;
V_50 = 1 << F_74 ( V_53 ) ;
if ( V_50 <= 1 )
return 1 ;
V_32 = F_75 ( & V_34 , 0 ) + 2 ;
if ( V_32 == 2 ) {
if ( V_48 != V_49 + 1 && V_48 != V_49 - 1 )
V_32 = 1 ;
V_49 = V_48 ;
} else {
unsigned int V_54 = 4 ;
while ( V_54 < V_32 )
V_54 <<= 1 ;
V_32 = V_54 ;
}
if ( V_32 > V_50 )
V_32 = V_50 ;
V_51 = F_76 ( & V_52 ) / 2 ;
if ( V_32 < V_51 )
V_32 = V_51 ;
F_77 ( & V_52 , V_32 ) ;
return V_32 ;
}
struct V_18 * F_78 ( T_1 V_19 , T_3 V_26 ,
struct V_35 * V_36 , unsigned long V_37 )
{
struct V_18 * V_18 ;
unsigned long V_55 = F_10 ( V_19 ) ;
unsigned long V_48 = V_55 ;
unsigned long V_56 , V_57 ;
unsigned long V_58 ;
struct V_59 V_60 ;
bool V_45 = true ;
V_58 = F_73 ( V_48 ) - 1 ;
if ( ! V_58 )
goto V_61;
V_45 = false ;
V_56 = V_48 & ~ V_58 ;
V_57 = V_48 | V_58 ;
if ( ! V_56 )
V_56 ++ ;
F_79 ( & V_60 ) ;
for ( V_48 = V_56 ; V_48 <= V_57 ; V_48 ++ ) {
V_18 = F_71 ( F_80 ( F_81 ( V_19 ) , V_48 ) ,
V_26 , V_36 , V_37 , false ) ;
if ( ! V_18 )
continue;
if ( V_48 != V_55 && F_22 ( ! F_57 ( V_18 ) ) )
F_82 ( V_18 ) ;
F_51 ( V_18 ) ;
}
F_83 ( & V_60 ) ;
F_53 () ;
V_61:
return F_71 ( V_19 , V_26 , V_36 , V_37 , V_45 ) ;
}
int F_84 ( unsigned int type , unsigned long V_62 )
{
struct V_5 * V_6 , * V_63 ;
unsigned int V_1 , V_3 ;
V_3 = F_85 ( V_62 , V_64 ) ;
V_6 = F_86 ( sizeof( struct V_5 ) * V_3 , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
V_63 = V_6 + V_1 ;
F_87 ( & V_63 -> V_23 , V_65 | V_31 ) ;
F_77 ( & V_63 -> V_66 , 0 ) ;
V_63 -> V_67 = & V_68 ;
F_88 ( V_63 ) ;
F_89 ( & V_63 -> V_21 ) ;
}
V_8 [ type ] = V_3 ;
F_90 ( V_9 [ type ] , V_6 ) ;
return 0 ;
}
void F_91 ( unsigned int type )
{
struct V_5 * V_6 ;
V_6 = V_9 [ type ] ;
V_8 [ type ] = 0 ;
F_90 ( V_9 [ type ] , NULL ) ;
F_92 () ;
F_93 ( V_6 ) ;
}
