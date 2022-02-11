static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_3 ,
V_6 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_2 -> V_8 )
V_4 = F_2 ( V_2 -> V_5 , V_3 ,
V_9 , 0 ) ;
V_7:
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_3 , unsigned int V_12 )
{
T_1 * * V_13 ;
struct V_14 V_15 ;
enum V_16 V_17 ;
unsigned int V_18 ;
int V_19 , V_4 ;
if ( V_11 == & V_2 -> V_20 ) {
V_13 = V_2 -> V_21 ;
V_17 = V_9 ;
} else {
V_13 = V_2 -> V_22 ;
V_17 = V_6 ;
}
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
V_4 = F_4 ( V_13 [ V_19 ] , & V_15 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_15 . V_3 == V_3 ) && ( V_15 . V_24 == V_12 ) )
break;
}
if ( V_19 == V_23 )
return - V_25 ;
if ( V_2 -> V_26 )
return F_1 ( V_2 , V_3 ) ;
V_18 = 5 + V_13 [ V_19 ] [ 4 ] * 2 ;
V_4 = F_5 ( V_2 -> V_5 , V_17 , 0 , V_13 [ V_19 ] , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( 100 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_10 * V_27 )
{
F_8 ( V_27 ) ;
F_9 ( V_27 ) ;
if ( V_27 == & V_2 -> V_20 )
F_10 ( & V_2 -> V_28 ) ;
else
F_10 ( & V_2 -> V_29 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_10 * V_27 ,
unsigned int V_3 , unsigned int V_12 )
{
T_1 * * V_13 ;
struct V_30 * V_31 ;
struct V_14 V_15 ;
unsigned int V_19 , V_32 ;
int V_4 ;
if ( V_27 == & V_2 -> V_33 ) {
V_13 = V_2 -> V_22 ;
V_31 = & V_2 -> V_29 ;
} else {
V_13 = V_2 -> V_21 ;
V_31 = & V_2 -> V_28 ;
}
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
if ( V_13 [ V_19 ] == NULL )
break;
V_4 = F_4 ( V_13 [ V_19 ] , & V_15 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_3 != V_15 . V_3 )
continue;
if ( V_12 == 0 || V_12 == V_15 . V_24 )
break;
}
if ( V_19 == V_23 ) {
V_4 = - V_25 ;
goto V_7;
}
V_12 = V_15 . V_24 ;
V_32 = F_12 ( V_15 . V_34 , 8 ) ;
if ( V_12 == 0 ) {
V_4 = - V_25 ;
goto V_7;
}
F_13 ( V_27 , V_3 , V_12 , V_32 ) ;
V_4 = F_14 ( V_31 ,
F_15 ( V_27 ) ) ;
if ( V_4 < 0 )
goto V_7;
V_4 = F_16 ( V_27 ,
V_31 -> V_35 . V_36 ,
V_31 -> V_37 ) ;
if ( V_4 < 0 ) {
F_10 ( V_31 ) ;
goto V_7;
}
if ( ! F_17 ( V_27 , V_38 ) ) {
F_7 ( V_2 , V_27 ) ;
V_4 = - V_39 ;
}
V_7:
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
bool V_40 ;
int V_4 ;
if ( V_27 == & V_2 -> V_20 )
V_31 = & V_2 -> V_28 ;
else
V_31 = & V_2 -> V_29 ;
V_4 = F_19 ( V_31 , & V_40 ) ;
if ( ( V_4 >= 0 ) && V_40 && ! F_20 ( V_27 ) ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_1 ,
( V_31 -> V_42 == V_43 ) ? 'o' : 'i' ,
V_31 -> V_44 ) ;
V_4 = - V_45 ;
}
return V_4 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
enum V_46 V_47 ;
enum V_48 V_49 ;
int V_4 ;
if ( V_27 == & V_2 -> V_20 ) {
V_31 = & V_2 -> V_28 ;
V_47 = V_43 ;
V_49 = V_50 ;
} else {
V_31 = & V_2 -> V_29 ;
V_47 = V_51 ;
V_49 = V_52 ;
}
V_4 = F_23 ( V_31 , V_2 -> V_5 , V_47 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
V_4 = F_24 ( V_27 , V_2 -> V_5 , V_49 , V_53 ) ;
if ( V_4 < 0 ) {
F_25 ( V_27 ) ;
F_26 ( V_31 ) ;
goto V_7;
}
if ( V_27 == & V_2 -> V_20 )
V_2 -> V_20 . V_54 |= V_55 |
V_56 ;
V_7:
return V_4 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_27 ,
unsigned int V_3 , unsigned int V_12 )
{
struct V_10 * V_57 ;
struct V_14 V_15 ;
enum V_16 V_17 ;
unsigned int V_58 , V_59 ;
int V_4 = 0 ;
if ( V_27 == & V_2 -> V_20 ) {
V_58 = V_2 -> V_60 ;
V_57 = & V_2 -> V_33 ;
V_59 = V_2 -> V_61 ;
V_17 = V_9 ;
} else {
V_58 = V_2 -> V_61 ;
V_59 = V_2 -> V_60 ;
if ( V_2 -> V_8 )
V_57 = & V_2 -> V_33 ;
else
V_57 = NULL ;
V_17 = V_6 ;
}
if ( V_58 == 0 )
goto V_7;
V_4 = F_18 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
goto V_7;
if ( F_28 ( V_27 ) )
F_7 ( V_2 , V_27 ) ;
V_4 = F_29 ( V_2 , V_17 , & V_15 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_3 == 0 )
V_3 = V_15 . V_3 ;
if ( V_12 == 0 )
V_12 = V_15 . V_24 ;
if ( ( V_15 . V_3 != V_3 ) || ( V_15 . V_24 != V_12 ) ) {
if ( V_57 != NULL ) {
V_4 = F_18 ( V_2 , V_57 ) ;
if ( V_4 < 0 )
goto V_7;
F_7 ( V_2 , V_57 ) ;
}
F_7 ( V_2 , V_27 ) ;
V_4 = F_3 ( V_2 , V_27 , V_3 , V_12 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_2 , V_4 ) ;
goto V_7;
}
if ( V_57 && ! F_20 ( V_57 ) &&
( V_59 > 0 ) ) {
V_4 = F_11 ( V_2 , V_57 , V_3 , 0 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_3 , V_4 ) ;
goto V_7;
}
}
}
if ( ! F_20 ( V_27 ) ) {
V_4 = F_11 ( V_2 , V_27 , V_3 , V_12 ) ;
if ( V_4 < 0 )
F_21 ( & V_2 -> V_5 -> V_41 ,
L_4 , V_4 ) ;
}
V_7:
return V_4 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
if ( ( ( V_27 == & V_2 -> V_20 ) && ( V_2 -> V_60 > 0 ) ) ||
( ( V_27 == & V_2 -> V_33 ) && ( V_2 -> V_61 > 0 ) ) )
return;
F_7 ( V_2 , V_27 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
if ( V_27 == & V_2 -> V_20 )
V_31 = & V_2 -> V_28 ;
else
V_31 = & V_2 -> V_29 ;
F_25 ( V_27 ) ;
F_26 ( V_31 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
if ( V_27 == & V_2 -> V_20 )
V_31 = & V_2 -> V_28 ;
else
V_31 = & V_2 -> V_29 ;
if ( F_33 ( V_31 ) < 0 )
F_7 ( V_2 , V_27 ) ;
else
F_34 ( V_27 ) ;
}
int F_29 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
struct V_14 * V_15 )
{
T_1 * V_62 ;
unsigned int V_18 ;
int V_4 ;
V_18 = V_63 ;
V_62 = F_35 ( V_18 , V_64 ) ;
if ( V_62 == NULL )
return - V_65 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , 0 , V_62 , & V_18 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_18 < 3 ) {
V_4 = - V_66 ;
goto V_7;
}
V_4 = F_4 ( V_62 , V_15 ) ;
V_7:
F_37 ( V_62 ) ;
return V_4 ;
}
int F_4 ( T_1 * V_62 ,
struct V_14 * V_15 )
{
unsigned int V_19 , V_67 , V_68 , type ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( ( V_62 [ 0 ] != 0x90 ) || ( V_62 [ 1 ] != 0x40 ) )
return - V_69 ;
for ( V_19 = 0 ; V_19 < F_38 ( V_70 ) ; V_19 ++ ) {
if ( V_62 [ 2 ] == V_70 [ V_19 ] )
break;
}
if ( V_19 == F_38 ( V_70 ) )
return - V_69 ;
V_15 -> V_3 = V_71 [ V_19 ] ;
for ( V_67 = 0 ; V_67 < V_62 [ 4 ] ; V_67 ++ ) {
V_68 = V_62 [ 5 + V_67 * 2 ] ;
type = V_62 [ 6 + V_67 * 2 ] ;
switch ( type ) {
case 0x00 :
case 0x06 :
V_15 -> V_24 += V_68 ;
break;
case 0x0d :
V_15 -> V_34 = V_68 ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
case 0x04 :
case 0x05 :
case 0x07 :
case 0x0c :
case 0x08 :
case 0x09 :
case 0x0a :
case 0x0b :
case 0x0e :
case 0x0f :
case 0x10 :
case 0x40 :
case 0xff :
default:
return - V_69 ;
}
}
if ( V_15 -> V_24 > V_72 ||
V_15 -> V_34 > V_73 )
return - V_69 ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , enum V_16 V_17 ,
unsigned int V_74 , T_1 * V_75 , unsigned int * V_18 ,
T_1 * * V_13 )
{
struct V_14 V_15 ;
unsigned int V_19 , V_76 ;
int V_4 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , V_74 , V_75 , V_18 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_5 ,
( V_17 == V_6 ) ? L_6 : L_7 ,
V_74 , V_4 ) ;
goto V_7;
}
V_76 = 0 ;
V_4 = F_4 ( V_75 , & V_15 ) ;
if ( V_4 < 0 )
goto V_7;
V_13 [ V_76 ] = F_40 ( V_75 , * V_18 , V_64 ) ;
if ( V_13 [ V_76 ] == NULL ) {
V_4 = - V_65 ;
goto V_7;
}
for ( V_19 = 0 ; V_19 < F_38 ( V_71 ) ; V_19 ++ ) {
if ( V_15 . V_3 == V_71 [ V_19 ] )
continue;
V_4 = F_41 ( V_2 -> V_5 ,
V_71 [ V_19 ] ,
V_17 , V_74 ) ;
if ( V_4 < 0 )
continue;
V_76 ++ ;
V_13 [ V_76 ] = F_40 ( V_75 , * V_18 , V_64 ) ;
if ( V_13 [ V_76 ] == NULL ) {
V_4 = - V_65 ;
goto V_7;
}
V_13 [ V_76 ] [ 2 ] = V_70 [ V_19 ] ;
}
V_4 = 0 ;
V_2 -> V_26 = true ;
V_7:
return V_4 ;
}
static int F_42 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
unsigned short V_74 )
{
T_1 * V_75 , * * V_13 ;
unsigned int V_18 , V_76 = 0 ;
struct V_14 V_77 ;
int V_4 ;
V_75 = F_35 ( V_63 , V_64 ) ;
if ( V_75 == NULL )
return - V_65 ;
if ( V_17 == V_9 )
V_13 = V_2 -> V_21 ;
else
V_13 = V_2 -> V_22 ;
V_18 = V_63 ;
V_4 = F_43 ( V_2 -> V_5 , V_17 , 0 , V_75 , & V_18 , 0 ) ;
if ( V_4 == - V_69 ) {
V_18 = V_63 ;
V_4 = F_39 ( V_2 , V_17 , V_74 , V_75 , & V_18 ,
V_13 ) ;
goto V_7;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_8 ,
V_76 , ( V_17 == V_6 ) ? L_6 : L_7 ,
V_74 , V_4 ) ;
goto V_7;
}
while ( V_76 < V_23 ) {
if ( V_18 < 3 ) {
V_4 = - V_66 ;
break;
}
V_4 = F_4 ( V_75 , & V_77 ) ;
if ( V_4 < 0 )
break;
V_13 [ V_76 ] = F_40 ( V_75 , V_18 , V_64 ) ;
if ( V_13 [ V_76 ] == NULL ) {
V_4 = - V_65 ;
break;
}
V_18 = V_63 ;
V_4 = F_43 ( V_2 -> V_5 , V_17 , 0 ,
V_75 , & V_18 , ++ V_76 ) ;
if ( V_4 == - V_25 ) {
V_4 = 0 ;
break;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_8 ,
V_76 , ( V_17 == V_6 ) ? L_6 :
L_7 ,
V_74 , V_4 ) ;
break;
}
}
V_7:
F_37 ( V_75 ) ;
return V_4 ;
}
int F_44 ( struct V_1 * V_2 )
{
T_1 V_78 [ V_79 ] ;
int V_4 ;
V_4 = F_45 ( V_2 -> V_5 , 0x1f , 0x07 , 0x00 , V_78 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_9 ,
V_4 ) ;
goto V_7;
} else if ( ( V_78 [ 0 ] == 0 ) && ( V_78 [ 1 ] == 0 ) ) {
V_4 = - V_69 ;
goto V_7;
}
if ( V_78 [ 1 ] > 0 ) {
V_4 = F_42 ( V_2 , V_9 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
V_2 -> V_8 = true ;
}
if ( V_78 [ 0 ] > 0 )
V_4 = F_42 ( V_2 , V_6 , 0 ) ;
V_7:
return V_4 ;
}
void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_80 = true ;
F_47 ( & V_2 -> V_81 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_4 ;
F_49 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_83 < 0 ) {
V_4 = - V_45 ;
goto V_7;
}
if ( V_2 -> V_83 ++ == 0 )
F_46 ( V_2 ) ;
V_4 = 0 ;
V_7:
F_50 ( & V_2 -> V_82 ) ;
return V_4 ;
}
void F_51 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_82 ) ;
if ( F_52 ( V_2 -> V_83 <= 0 ) )
goto V_7;
if ( -- V_2 -> V_83 == 0 )
F_46 ( V_2 ) ;
V_7:
F_50 ( & V_2 -> V_82 ) ;
}
