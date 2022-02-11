static T_1 * F_1 ( T_1 * V_1 , int * V_2 , int * V_3 )
{
T_1 V_4 ;
int V_5 , V_6 , V_7 ;
* V_2 = 0 ;
* V_3 = 0 ;
V_6 = 6 ;
V_4 = * V_1 ;
V_7 = 0 ;
while ( 1 ) {
V_5 = ( V_4 >> V_6 ) & 0x03 ;
switch ( V_5 ) {
case V_8 :
( * V_3 ) ++ ;
case V_9 :
case V_10 :
( * V_2 ) ++ ;
case V_11 :
break;
}
V_6 -= 2 ;
if ( V_6 == 0 ) {
if ( ! F_2 ( V_4 ) )
return V_1 + 1 ;
V_6 = 16 ;
V_1 ++ ;
V_4 = * V_1 ;
if ( ! F_3 ( V_4 ) ||
V_7 != F_4 ( V_4 ) )
return NULL ;
V_7 ++ ;
}
}
}
static int F_5 ( T_1 * V_1 , int V_12 )
{
int V_13 , V_6 ;
V_13 = ( V_12 + 5 ) / 8 ;
V_6 = 16 - ( ( V_12 + 5 ) & 7 ) * 2 ;
return ( V_1 [ V_13 ] >> V_6 ) & 0x03 ;
}
static struct V_14 * F_6 ( T_1 V_1 , int V_15 , int V_16 )
{
struct V_14 * V_17 ;
V_17 = F_7 ( sizeof( * V_17 ) + V_15 * sizeof( V_17 -> V_18 [ 0 ] ) ,
V_19 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_16 = V_16 ;
V_17 -> V_20 = V_21 | F_8 ( V_1 ) ;
V_17 -> V_22 = F_9 ( V_1 ) ;
V_17 -> V_23 = F_10 ( V_1 ) ;
V_17 -> V_24 = F_11 ( V_1 ) ;
V_17 -> V_15 = V_15 ;
F_12 ( & V_17 -> V_25 , 1 ) ;
F_13 ( & V_17 -> V_26 ) ;
return V_17 ;
}
static void F_14 ( struct V_14 * V_17 )
{
int V_27 [ 2 ] = { - 1 , - 1 } ;
int V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_17 -> V_15 ; V_29 ++ ) {
if ( V_17 -> V_18 [ V_29 ] == NULL )
continue;
if ( V_17 -> V_18 [ V_29 ] -> V_30 > V_28 )
V_28 = V_17 -> V_18 [ V_29 ] -> V_30 ;
if ( V_17 -> V_18 [ V_29 ] -> V_31 > V_27 [ 0 ] ) {
V_27 [ 1 ] = V_27 [ 0 ] ;
V_27 [ 0 ] = V_17 -> V_18 [ V_29 ] -> V_31 ;
} else if ( V_17 -> V_18 [ V_29 ] -> V_31 > V_27 [ 1 ] )
V_27 [ 1 ] = V_17 -> V_18 [ V_29 ] -> V_31 ;
}
V_17 -> V_31 = V_27 [ 0 ] + 1 ;
V_17 -> V_30 = F_15 ( V_28 , V_27 [ 0 ] + V_27 [ 1 ] + 2 ) ;
}
static inline struct V_14 * V_14 ( struct V_32 * V_33 )
{
return F_16 ( V_33 , struct V_14 , V_26 ) ;
}
static struct V_14 * F_17 ( struct V_34 * V_35 ,
T_1 * V_1 , int V_36 )
{
struct V_14 * V_17 , * V_37 , * V_38 , * V_39 ;
struct V_32 V_40 , * V_41 ;
T_1 * V_42 , * V_43 , V_4 ;
int V_29 , V_15 , V_3 , V_44 , V_45 , V_46 ;
int V_47 ;
bool V_48 ;
V_38 = NULL ;
V_17 = NULL ;
F_13 ( & V_40 ) ;
V_46 = 0 ;
V_43 = V_1 + V_36 ;
V_44 = 0 ;
V_39 = NULL ;
V_47 = F_18 ( * V_1 ) ;
V_48 = false ;
while ( V_1 < V_43 ) {
V_42 = F_1 ( V_1 , & V_15 , & V_3 ) ;
if ( V_42 == NULL ) {
F_19 ( V_35 , L_1 ) ;
return NULL ;
}
V_4 = * V_1 ;
if ( V_44 != F_8 ( V_4 ) ) {
F_19 ( V_35 , L_2 ,
V_44 , F_8 ( V_4 ) ) ;
return NULL ;
}
if ( V_3 > V_46 ) {
F_19 ( V_35 , L_3 ) ;
return NULL ;
}
for ( V_29 = 0 , V_41 = & V_40 ; V_29 < V_3 ; V_29 ++ )
V_41 = V_41 -> V_49 ;
V_37 = V_14 ( V_41 ) ;
V_17 = F_6 ( V_4 , V_15 , V_35 -> V_16 ) ;
if ( V_17 == NULL ) {
F_19 ( V_35 , L_4 ) ;
return NULL ;
}
if ( V_44 == ( V_35 -> V_20 & 0x3f ) )
V_38 = V_17 ;
if ( F_20 ( V_4 ) )
V_39 = V_17 ;
V_45 = 0 ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ ) {
switch ( F_5 ( V_1 , V_29 ) ) {
case V_9 :
V_45 ++ ;
V_17 -> V_16 = V_29 ;
break;
case V_8 :
V_17 -> V_18 [ V_29 ] = V_37 ;
V_37 -> V_18 [ V_37 -> V_16 ] = V_17 ;
V_37 -> V_16 = V_35 -> V_16 ;
V_37 = V_14 ( V_37 -> V_26 . V_50 ) ;
break;
}
}
if ( ( V_42 == V_43 && V_45 != 0 ) ||
( V_42 < V_43 && V_45 != 1 ) ) {
F_19 ( V_35 , L_5
L_6 , V_44 , V_45 ) ;
return NULL ;
}
F_21 ( V_41 -> V_49 , & V_40 ) ;
F_22 ( & V_17 -> V_26 , & V_40 ) ;
V_46 += 1 - V_3 ;
if ( V_17 -> V_23 == V_51 &&
V_45 + V_3 > 1 )
V_48 = true ;
if ( F_18 ( V_4 ) != V_47 )
V_47 = 0 ;
F_14 ( V_17 ) ;
V_1 = V_42 ;
V_44 ++ ;
}
V_35 -> V_52 = V_17 ;
V_35 -> V_39 = V_39 ;
V_35 -> V_47 = V_47 ;
V_35 -> V_48 = V_48 ;
return V_38 ;
}
static void F_23 ( struct V_34 * V_35 , struct V_14 * V_53 ,
T_2 V_54 )
{
struct V_32 V_55 ;
struct V_14 * V_17 , * V_50 , * V_37 , * V_56 ;
int V_29 ;
F_13 ( & V_55 ) ;
F_24 ( V_53 ) ;
F_22 ( & V_53 -> V_26 , & V_55 ) ;
V_56 = NULL ;
F_25 (node, &list, link) {
V_17 -> V_16 = V_35 -> V_16 ;
for ( V_29 = 0 ; V_29 < V_17 -> V_15 ; V_29 ++ ) {
V_37 = V_17 -> V_18 [ V_29 ] ;
if ( ! V_37 )
continue;
if ( V_37 -> V_16 == V_35 -> V_16 )
V_56 = V_37 ;
else {
F_24 ( V_37 ) ;
F_22 ( & V_37 -> V_26 , & V_55 ) ;
}
}
V_54 ( V_35 , V_17 , V_56 ) ;
}
F_26 (node, next, &list, link)
F_27 ( V_17 ) ;
}
static void F_28 ( struct V_34 * V_35 ,
struct V_14 * V_17 , struct V_14 * V_56 )
{
F_29 ( V_35 , V_17 , V_57 ) ;
F_27 ( V_17 ) ;
V_35 -> V_58 = 0 ;
}
static void F_30 ( struct V_34 * V_35 ,
struct V_14 * V_17 , struct V_14 * V_56 )
{
int V_59 = ( V_17 -> V_23 == V_51 ) ;
if ( V_56 != NULL ) {
V_17 -> V_60 = V_56 -> V_60 < V_17 -> V_23 ?
V_56 -> V_60 : V_17 -> V_23 ;
V_17 -> V_59 = V_56 -> V_59 && V_59 ;
} else {
V_17 -> V_60 = V_17 -> V_23 ;
V_17 -> V_59 = V_59 ;
}
F_29 ( V_35 , V_17 , V_61 ) ;
V_35 -> V_58 = 0 ;
}
void F_31 ( struct V_34 * V_35 )
{
unsigned long V_62 ;
F_32 ( & V_35 -> V_63 , V_62 ) ;
V_35 -> V_16 ++ ;
if ( V_35 -> V_38 != NULL )
F_23 ( V_35 , V_35 -> V_38 , F_28 ) ;
V_35 -> V_38 = NULL ;
F_33 ( & V_35 -> V_63 , V_62 ) ;
}
static void F_34 ( struct V_14 * V_64 , struct V_14 * V_65 , int V_66 )
{
struct V_14 * V_67 ;
int V_29 ;
V_67 = V_65 -> V_18 [ V_66 ] ;
V_64 -> V_18 [ V_66 ] = V_67 ;
for ( V_29 = 0 ; V_29 < V_67 -> V_15 ; V_29 ++ ) {
if ( V_67 -> V_18 [ V_29 ] == V_65 ) {
V_67 -> V_18 [ V_29 ] = V_64 ;
break;
}
}
}
static void F_35 ( struct V_34 * V_35 , struct V_14 * V_53 )
{
struct V_32 V_68 , V_69 ;
struct V_14 * V_64 , * V_65 , * V_70 ;
int V_29 , V_71 ;
F_13 ( & V_68 ) ;
F_22 ( & V_35 -> V_38 -> V_26 , & V_68 ) ;
F_13 ( & V_69 ) ;
F_22 ( & V_53 -> V_26 , & V_69 ) ;
V_64 = V_14 ( V_68 . V_50 ) ;
V_65 = V_14 ( V_69 . V_50 ) ;
while ( & V_64 -> V_26 != & V_68 ) {
F_36 ( V_64 -> V_15 != V_65 -> V_15 ) ;
if ( V_64 -> V_22 && ! V_65 -> V_22 )
V_71 = V_72 ;
else if ( ! V_64 -> V_22 && V_65 -> V_22 )
V_71 = V_73 ;
else if ( V_65 -> V_24 && V_65 -> V_22 )
V_71 = V_74 ;
else
V_71 = V_75 ;
V_64 -> V_20 = V_65 -> V_20 ;
V_64 -> V_16 = V_35 -> V_16 ;
V_64 -> V_22 = V_65 -> V_22 ;
V_64 -> V_24 = V_65 -> V_24 ;
V_64 -> V_30 = V_65 -> V_30 ;
V_65 -> V_16 = V_35 -> V_16 ;
F_29 ( V_35 , V_64 , V_71 ) ;
if ( V_35 -> V_52 == V_65 )
V_35 -> V_52 = V_64 ;
if ( V_35 -> V_39 == V_65 )
V_35 -> V_39 = V_64 ;
for ( V_29 = 0 ; V_29 < V_64 -> V_15 ; V_29 ++ ) {
if ( V_64 -> V_18 [ V_29 ] && V_65 -> V_18 [ V_29 ] ) {
if ( V_64 -> V_18 [ V_29 ] -> V_16 == V_35 -> V_16 )
continue;
F_22 ( & V_64 -> V_18 [ V_29 ] -> V_26 , & V_68 ) ;
F_22 ( & V_65 -> V_18 [ V_29 ] -> V_26 , & V_69 ) ;
} else if ( V_64 -> V_18 [ V_29 ] ) {
F_23 ( V_35 , V_64 -> V_18 [ V_29 ] ,
F_28 ) ;
V_64 -> V_18 [ V_29 ] = NULL ;
} else if ( V_65 -> V_18 [ V_29 ] ) {
F_34 ( V_64 , V_65 , V_29 ) ;
F_23 ( V_35 , V_64 -> V_18 [ V_29 ] ,
F_30 ) ;
}
}
V_64 = V_14 ( V_64 -> V_26 . V_50 ) ;
V_70 = V_14 ( V_65 -> V_26 . V_50 ) ;
F_27 ( V_65 ) ;
V_65 = V_70 ;
}
}
static void F_37 ( struct V_34 * V_35 ,
T_1 * V_76 , int V_36 )
{
int V_77 = ( V_35 -> V_52 -> V_20 & 0x3f ) + 1 ;
T_3 * V_78 = V_35 -> V_79 ;
* V_78 ++ = F_38 ( ( V_36 + 2 ) << 16 ) ;
* V_78 ++ = F_38 ( F_39 ( V_35 -> V_79 [ 1 ] ) + 1 ) ;
* V_78 ++ = F_38 ( ( V_77 << 16 ) | V_36 ) ;
while ( V_36 -- )
* V_78 ++ = F_40 ( V_76 ++ ) ;
F_41 ( V_35 -> V_79 ) ;
}
void F_42 ( struct V_34 * V_35 , int V_20 , int V_80 ,
int V_36 , T_1 * V_76 , bool V_81 )
{
struct V_14 * V_38 ;
unsigned long V_62 ;
if ( ! F_43 ( V_80 , V_35 -> V_80 ) &&
V_35 -> V_38 != NULL ) {
F_31 ( V_35 ) ;
V_35 -> V_58 = 0 ;
}
F_32 ( & V_35 -> V_63 , V_62 ) ;
V_35 -> V_82 = V_35 -> V_83 ;
V_35 -> V_20 = V_20 ;
F_44 () ;
V_35 -> V_80 = V_80 ;
V_35 -> V_84 = F_45 () ;
V_35 -> V_85 = 0xffff ;
V_35 -> V_81 = V_81 ;
F_46 ( V_35 , 0 ) ;
V_38 = F_17 ( V_35 , V_76 , V_36 ) ;
F_37 ( V_35 , V_76 , V_36 ) ;
V_35 -> V_16 ++ ;
if ( V_38 == NULL ) {
F_19 ( V_35 , L_7 ) ;
} else if ( V_35 -> V_38 == NULL ) {
V_35 -> V_38 = V_38 ;
F_23 ( V_35 , V_38 , F_30 ) ;
} else {
F_35 ( V_35 , V_38 ) ;
}
F_33 ( & V_35 -> V_63 , V_62 ) ;
}
