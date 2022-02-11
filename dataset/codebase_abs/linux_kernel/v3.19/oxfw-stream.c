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
V_4 = F_17 ( V_27 , V_38 ) ;
if ( V_4 < 0 )
F_7 ( V_2 , V_27 ) ;
V_7:
return V_4 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
bool V_39 ;
int V_4 ;
if ( V_27 == & V_2 -> V_20 )
V_31 = & V_2 -> V_28 ;
else
V_31 = & V_2 -> V_29 ;
V_4 = F_19 ( V_31 , & V_39 ) ;
if ( ( V_4 >= 0 ) && V_39 && ! F_20 ( V_27 ) ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_1 ,
( V_31 -> V_41 == V_42 ) ? 'o' : 'i' ,
V_31 -> V_43 ) ;
V_4 = - V_44 ;
}
return V_4 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
struct V_30 * V_31 ;
enum V_45 V_46 ;
enum V_47 V_48 ;
int V_4 ;
if ( V_27 == & V_2 -> V_20 ) {
V_31 = & V_2 -> V_28 ;
V_46 = V_42 ;
V_48 = V_49 ;
} else {
V_31 = & V_2 -> V_29 ;
V_46 = V_50 ;
V_48 = V_51 ;
}
V_4 = F_23 ( V_31 , V_2 -> V_5 , V_46 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
V_4 = F_24 ( V_27 , V_2 -> V_5 , V_48 , V_52 ) ;
if ( V_4 < 0 ) {
F_25 ( V_27 ) ;
F_26 ( V_31 ) ;
goto V_7;
}
if ( V_27 == & V_2 -> V_20 )
V_2 -> V_20 . V_53 |= V_54 ;
V_7:
return V_4 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_27 ,
unsigned int V_3 , unsigned int V_12 )
{
struct V_10 * V_55 ;
struct V_14 V_15 ;
enum V_16 V_17 ;
unsigned int V_56 , V_57 ;
int V_4 = 0 ;
if ( V_27 == & V_2 -> V_20 ) {
V_56 = V_2 -> V_58 ;
V_55 = & V_2 -> V_33 ;
V_57 = V_2 -> V_59 ;
V_17 = V_9 ;
} else {
V_56 = V_2 -> V_59 ;
V_57 = V_2 -> V_58 ;
if ( V_2 -> V_8 )
V_55 = & V_2 -> V_33 ;
else
V_55 = NULL ;
V_17 = V_6 ;
}
if ( V_56 == 0 )
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
if ( V_55 != NULL ) {
V_4 = F_18 ( V_2 , V_55 ) ;
if ( V_4 < 0 )
goto V_7;
F_7 ( V_2 , V_55 ) ;
}
F_7 ( V_2 , V_27 ) ;
V_4 = F_3 ( V_2 , V_27 , V_3 , V_12 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_2 , V_4 ) ;
goto V_7;
}
if ( V_55 && ! F_20 ( V_55 ) &&
( V_57 > 0 ) ) {
V_4 = F_11 ( V_2 , V_55 , V_3 , 0 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_3 , V_4 ) ;
goto V_7;
}
}
}
if ( ! F_20 ( V_27 ) ) {
V_4 = F_11 ( V_2 , V_27 , V_3 , V_12 ) ;
if ( V_4 < 0 )
F_21 ( & V_2 -> V_5 -> V_40 ,
L_4 , V_4 ) ;
}
V_7:
return V_4 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_10 * V_27 )
{
if ( ( ( V_27 == & V_2 -> V_20 ) && ( V_2 -> V_58 > 0 ) ) ||
( ( V_27 == & V_2 -> V_33 ) && ( V_2 -> V_59 > 0 ) ) )
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
F_7 ( V_2 , V_27 ) ;
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
T_1 * V_60 ;
unsigned int V_18 ;
int V_4 ;
V_18 = V_61 ;
V_60 = F_35 ( V_18 , V_62 ) ;
if ( V_60 == NULL )
return - V_63 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , 0 , V_60 , & V_18 ) ;
if ( V_4 < 0 )
goto V_7;
if ( V_18 < 3 ) {
V_4 = - V_64 ;
goto V_7;
}
V_4 = F_4 ( V_60 , V_15 ) ;
V_7:
F_37 ( V_60 ) ;
return V_4 ;
}
int F_4 ( T_1 * V_60 ,
struct V_14 * V_15 )
{
unsigned int V_19 , V_65 , V_66 , type ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( ( V_60 [ 0 ] != 0x90 ) || ( V_60 [ 1 ] != 0x40 ) )
return - V_67 ;
for ( V_19 = 0 ; V_19 < F_38 ( V_68 ) ; V_19 ++ ) {
if ( V_60 [ 2 ] == V_68 [ V_19 ] )
break;
}
if ( V_19 == F_38 ( V_68 ) )
return - V_67 ;
V_15 -> V_3 = V_69 [ V_19 ] ;
for ( V_65 = 0 ; V_65 < V_60 [ 4 ] ; V_65 ++ ) {
V_66 = V_60 [ 5 + V_65 * 2 ] ;
type = V_60 [ 6 + V_65 * 2 ] ;
switch ( type ) {
case 0x00 :
case 0x06 :
V_15 -> V_24 += V_66 ;
break;
case 0x0d :
V_15 -> V_34 = V_66 ;
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
return - V_67 ;
}
}
if ( V_15 -> V_24 > V_70 ||
V_15 -> V_34 > V_71 )
return - V_67 ;
return 0 ;
}
static int
F_39 ( struct V_1 * V_2 , enum V_16 V_17 ,
unsigned int V_72 , T_1 * V_73 , unsigned int * V_18 ,
T_1 * * V_13 )
{
struct V_14 V_15 ;
unsigned int V_19 , V_74 ;
int V_4 ;
V_4 = F_36 ( V_2 -> V_5 , V_17 , V_72 , V_73 , V_18 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_5 ,
( V_17 == V_6 ) ? L_6 : L_7 ,
V_72 , V_4 ) ;
goto V_7;
}
V_74 = 0 ;
V_4 = F_4 ( V_73 , & V_15 ) ;
if ( V_4 < 0 )
goto V_7;
V_13 [ V_74 ] = F_35 ( * V_18 , V_62 ) ;
if ( V_13 [ V_74 ] == NULL ) {
V_4 = - V_63 ;
goto V_7;
}
memcpy ( V_13 [ V_74 ] , V_73 , * V_18 ) ;
for ( V_19 = 0 ; V_19 < F_38 ( V_69 ) ; V_19 ++ ) {
if ( V_15 . V_3 == V_69 [ V_19 ] )
continue;
V_4 = F_40 ( V_2 -> V_5 ,
V_69 [ V_19 ] ,
V_17 , V_72 ) ;
if ( V_4 < 0 )
continue;
V_74 ++ ;
V_13 [ V_74 ] = F_35 ( * V_18 , V_62 ) ;
if ( V_13 [ V_74 ] == NULL ) {
V_4 = - V_63 ;
goto V_7;
}
memcpy ( V_13 [ V_74 ] , V_73 , * V_18 ) ;
V_13 [ V_74 ] [ 2 ] = V_68 [ V_19 ] ;
}
V_4 = 0 ;
V_2 -> V_26 = true ;
V_7:
return V_4 ;
}
static int F_41 ( struct V_1 * V_2 ,
enum V_16 V_17 ,
unsigned short V_72 )
{
T_1 * V_73 , * * V_13 ;
unsigned int V_18 , V_74 = 0 ;
struct V_14 V_75 ;
int V_4 ;
V_73 = F_35 ( V_61 , V_62 ) ;
if ( V_73 == NULL )
return - V_63 ;
if ( V_17 == V_9 )
V_13 = V_2 -> V_21 ;
else
V_13 = V_2 -> V_22 ;
V_18 = V_61 ;
V_4 = F_42 ( V_2 -> V_5 , V_17 , 0 , V_73 , & V_18 , 0 ) ;
if ( V_4 == - V_67 ) {
V_18 = V_61 ;
V_4 = F_39 ( V_2 , V_17 , V_72 , V_73 , & V_18 ,
V_13 ) ;
goto V_7;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_8 ,
V_74 , ( V_17 == V_6 ) ? L_6 : L_7 ,
V_72 , V_4 ) ;
goto V_7;
}
while ( V_74 < V_23 ) {
if ( V_18 < 3 ) {
V_4 = - V_64 ;
break;
}
V_4 = F_4 ( V_73 , & V_75 ) ;
if ( V_4 < 0 )
break;
V_13 [ V_74 ] = F_35 ( V_18 , V_62 ) ;
if ( V_13 [ V_74 ] == NULL ) {
V_4 = - V_63 ;
break;
}
memcpy ( V_13 [ V_74 ] , V_73 , V_18 ) ;
V_18 = V_61 ;
V_4 = F_42 ( V_2 -> V_5 , V_17 , 0 ,
V_73 , & V_18 , ++ V_74 ) ;
if ( V_4 == - V_25 ) {
V_4 = 0 ;
break;
} else if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_8 ,
V_74 , ( V_17 == V_6 ) ? L_6 :
L_7 ,
V_72 , V_4 ) ;
break;
}
}
V_7:
F_37 ( V_73 ) ;
return V_4 ;
}
int F_43 ( struct V_1 * V_2 )
{
T_1 V_76 [ V_77 ] ;
int V_4 ;
V_4 = F_44 ( V_2 -> V_5 , 0x1f , 0x07 , 0x00 , V_76 ) ;
if ( V_4 < 0 ) {
F_21 ( & V_2 -> V_5 -> V_40 ,
L_9 ,
V_4 ) ;
goto V_7;
} else if ( ( V_76 [ 0 ] == 0 ) && ( V_76 [ 1 ] == 0 ) ) {
V_4 = - V_67 ;
goto V_7;
}
if ( V_76 [ 1 ] > 0 ) {
V_4 = F_41 ( V_2 , V_9 , 0 ) ;
if ( V_4 < 0 )
goto V_7;
V_2 -> V_8 = true ;
}
if ( V_76 [ 0 ] > 0 )
V_4 = F_41 ( V_2 , V_6 , 0 ) ;
V_7:
return V_4 ;
}
void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_78 = true ;
F_46 ( & V_2 -> V_79 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_4 ;
F_48 ( & V_2 -> V_80 ) ;
if ( V_2 -> V_81 < 0 ) {
V_4 = - V_44 ;
goto V_7;
}
if ( V_2 -> V_81 ++ == 0 )
F_45 ( V_2 ) ;
V_4 = 0 ;
V_7:
F_49 ( & V_2 -> V_80 ) ;
return V_4 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_80 ) ;
if ( F_51 ( V_2 -> V_81 <= 0 ) )
goto V_7;
if ( -- V_2 -> V_81 == 0 )
F_45 ( V_2 ) ;
V_7:
F_49 ( & V_2 -> V_80 ) ;
}
