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
V_2 -> V_20 . V_54 |= V_55 ;
V_7:
return V_4 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_27 ,
unsigned int V_3 , unsigned int V_12 )
{
struct V_10 * V_56 ;
struct V_14 V_15 ;
enum V_16 V_17 ;
unsigned int V_57 , V_58 ;
int V_4 = 0 ;
if ( V_27 == & V_2 -> V_20 ) {
V_57 = V_2 -> V_59 ;
V_56 = & V_2 -> V_33 ;
V_58 = V_2 -> V_60 ;
V_17 = V_9 ;
} else {
V_57 = V_2 -> V_60 ;
V_58 = V_2 -> V_59 ;
if ( V_2 -> V_8 )
V_56 = & V_2 -> V_33 ;
else
V_56 = NULL ;
V_17 = V_6 ;
}
if ( V_57 == 0 )
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
if ( V_56 != NULL ) {
V_4 = F_18 ( V_2 , V_56 ) ;
if ( V_4 < 0 )
goto V_7;
F_7 ( V_2 , V_56 ) ;
}
F_7 ( V_2 , V_27 ) ;
V_4 = F_3 ( V_2 , V_27 , V_3 , V_12 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_2 , V_4 ) ;
goto V_7;
}
if ( V_56 && ! F_20 ( V_56 ) &&
( V_58 > 0 ) ) {
V_4 = F_11 ( V_2 , V_56 , V_3 , 0 ) ;
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
if ( ( ( V_27 == & V_2 -> V_20 ) && ( V_2 -> V_59 > 0 ) ) ||
( ( V_27 == & V_2 -> V_33 ) && ( V_2 -> V_60 > 0 ) ) )
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
T_1 * V_61 ;
unsigned int V_18 ;
int V_4 ;
V_18 = V_62 ;
V_61 = F_35 ( V_18 , V_63 ) ;
if ( V_61 == NULL )
return - V_64 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , 0 , V_61 , & V_18 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_18 < 3 ) {
V_4 = - V_65 ;
goto V_7;
}
V_4 = F_4 ( V_61 , V_15 ) ;
V_7:
F_37 ( V_61 ) ;
return V_4 ;
}
int F_4 ( T_1 * V_61 ,
struct V_14 * V_15 )
{
unsigned int V_19 , V_66 , V_67 , type ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( ( V_61 [ 0 ] != 0x90 ) || ( V_61 [ 1 ] != 0x40 ) )
return - V_68 ;
for ( V_19 = 0 ; V_19 < F_38 ( V_69 ) ; V_19 ++ ) {
if ( V_61 [ 2 ] == V_69 [ V_19 ] )
break;
}
if ( V_19 == F_38 ( V_69 ) )
return - V_68 ;
V_15 -> V_3 = V_70 [ V_19 ] ;
for ( V_66 = 0 ; V_66 < V_61 [ 4 ] ; V_66 ++ ) {
V_67 = V_61 [ 5 + V_66 * 2 ] ;
type = V_61 [ 6 + V_66 * 2 ] ;
switch ( type ) {
case 0x00 :
case 0x06 :
V_15 -> V_24 += V_67 ;
break;
case 0x0d :
V_15 -> V_34 = V_67 ;
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
return - V_68 ;
}
}
if ( V_15 -> V_24 > V_71 ||
V_15 -> V_34 > V_72 )
return - V_68 ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , enum V_16 V_17 ,
unsigned int V_73 , T_1 * V_74 , unsigned int * V_18 ,
T_1 * * V_13 )
{
struct V_14 V_15 ;
unsigned int V_19 , V_75 ;
int V_4 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , V_73 , V_74 , V_18 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_5 ,
( V_17 == V_6 ) ? L_6 : L_7 ,
V_73 , V_4 ) ;
goto V_7;
}
V_75 = 0 ;
V_4 = F_4 ( V_74 , & V_15 ) ;
if ( V_4 < 0 )
goto V_7;
V_13 [ V_75 ] = F_35 ( * V_18 , V_63 ) ;
if ( V_13 [ V_75 ] == NULL ) {
V_4 = - V_64 ;
goto V_7;
}
memcpy ( V_13 [ V_75 ] , V_74 , * V_18 ) ;
for ( V_19 = 0 ; V_19 < F_38 ( V_70 ) ; V_19 ++ ) {
if ( V_15 . V_3 == V_70 [ V_19 ] )
continue;
V_4 = F_40 ( V_2 -> V_5 ,
V_70 [ V_19 ] ,
V_17 , V_73 ) ;
if ( V_4 < 0 )
continue;
V_75 ++ ;
V_13 [ V_75 ] = F_35 ( * V_18 , V_63 ) ;
if ( V_13 [ V_75 ] == NULL ) {
V_4 = - V_64 ;
goto V_7;
}
memcpy ( V_13 [ V_75 ] , V_74 , * V_18 ) ;
V_13 [ V_75 ] [ 2 ] = V_69 [ V_19 ] ;
}
V_4 = 0 ;
V_2 -> V_26 = true ;
V_7:
return V_4 ;
}
static int F_41 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
unsigned short V_73 )
{
T_1 * V_74 , * * V_13 ;
unsigned int V_18 , V_75 = 0 ;
struct V_14 V_76 ;
int V_4 ;
V_74 = F_35 ( V_62 , V_63 ) ;
if ( V_74 == NULL )
return - V_64 ;
if ( V_17 == V_9 )
V_13 = V_2 -> V_21 ;
else
V_13 = V_2 -> V_22 ;
V_18 = V_62 ;
V_4 = F_42 ( V_2 -> V_5 , V_17 , 0 , V_74 , & V_18 , 0 ) ;
if ( V_4 == - V_68 ) {
V_18 = V_62 ;
V_4 = F_39 ( V_2 , V_17 , V_73 , V_74 , & V_18 ,
V_13 ) ;
goto V_7;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_8 ,
V_75 , ( V_17 == V_6 ) ? L_6 : L_7 ,
V_73 , V_4 ) ;
goto V_7;
}
while ( V_75 < V_23 ) {
if ( V_18 < 3 ) {
V_4 = - V_65 ;
break;
}
V_4 = F_4 ( V_74 , & V_76 ) ;
if ( V_4 < 0 )
break;
V_13 [ V_75 ] = F_35 ( V_18 , V_63 ) ;
if ( V_13 [ V_75 ] == NULL ) {
V_4 = - V_64 ;
break;
}
memcpy ( V_13 [ V_75 ] , V_74 , V_18 ) ;
V_18 = V_62 ;
V_4 = F_42 ( V_2 -> V_5 , V_17 , 0 ,
V_74 , & V_18 , ++ V_75 ) ;
if ( V_4 == - V_25 ) {
V_4 = 0 ;
break;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_8 ,
V_75 , ( V_17 == V_6 ) ? L_6 :
L_7 ,
V_73 , V_4 ) ;
break;
}
}
V_7:
F_37 ( V_74 ) ;
return V_4 ;
}
int F_43 ( struct V_1 * V_2 )
{
T_1 V_77 [ V_78 ] ;
int V_4 ;
V_4 = F_44 ( V_2 -> V_5 , 0x1f , 0x07 , 0x00 , V_77 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_41 ,
L_9 ,
V_4 ) ;
goto V_7;
} else if ( ( V_77 [ 0 ] == 0 ) && ( V_77 [ 1 ] == 0 ) ) {
V_4 = - V_68 ;
goto V_7;
}
if ( V_77 [ 1 ] > 0 ) {
V_4 = F_41 ( V_2 , V_9 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
V_2 -> V_8 = true ;
}
if ( V_77 [ 0 ] > 0 )
V_4 = F_41 ( V_2 , V_6 , 0 ) ;
V_7:
return V_4 ;
}
void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_79 = true ;
F_46 ( & V_2 -> V_80 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_4 ;
F_48 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_82 < 0 ) {
V_4 = - V_45 ;
goto V_7;
}
if ( V_2 -> V_82 ++ == 0 )
F_45 ( V_2 ) ;
V_4 = 0 ;
V_7:
F_49 ( & V_2 -> V_81 ) ;
return V_4 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_81 ) ;
if ( F_51 ( V_2 -> V_82 <= 0 ) )
goto V_7;
if ( -- V_2 -> V_82 == 0 )
F_45 ( V_2 ) ;
V_7:
F_49 ( & V_2 -> V_81 ) ;
}
