static int F_1 ( struct V_1 * V_2 , const char * V_3 )
{
T_1 V_4 = 0 ;
if ( F_2 ( V_2 , V_5 , & V_4 ) ||
( V_4 & 5 ) != 5 ) {
if ( ( V_4 & 0xa ) != 0xa ) {
F_3 ( V_6 L_1
L_2 , V_3 , F_4 ( V_2 ) ) ;
return - V_7 ;
}
F_3 ( V_6 L_3
L_4 , V_3 , F_4 ( V_2 ) ) ;
( void ) F_5 ( V_2 , V_5 , V_4 | 5 ) ;
if ( F_2 ( V_2 , V_5 , & V_4 ) ||
( V_4 & 5 ) != 5 ) {
F_3 ( V_8 L_5
L_6 ,
V_3 , F_4 ( V_2 ) , V_4 | 5 , V_4 ) ;
return - V_7 ;
}
}
return 0 ;
}
static int F_6 ( unsigned long V_9 , const char * V_3 )
{
T_1 V_10 = F_7 ( V_9 + 2 ) ;
F_8 ( V_10 & 0x60 , V_9 + 2 ) ;
V_10 = F_7 ( V_9 + 2 ) ;
return ( V_10 & 0x80 ) ? 1 : 0 ;
}
unsigned long F_9 ( T_2 * V_11 , const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_2 ) ;
unsigned long V_9 = 0 ;
if ( V_11 -> V_14 & V_15 )
return V_11 -> V_9 ;
if ( V_11 -> V_16 && V_11 -> V_16 -> V_9 ) {
V_9 = V_11 -> V_16 -> V_9 - ( V_11 -> V_17 ? 0 : 8 ) ;
} else {
T_1 V_18 = ( V_13 -> V_14 & V_19 ) ? 2 : 4 ;
V_9 = F_11 ( V_2 , V_18 ) ;
if ( V_9 == 0 ) {
F_3 ( V_8 L_7 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return 0 ;
}
}
if ( V_11 -> V_17 )
V_9 += 8 ;
return V_9 ;
}
int F_12 ( T_2 * V_11 , const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_2 ) ;
T_1 V_10 ;
if ( V_13 -> V_14 & ( V_15 | V_19 ) )
goto V_20;
if ( V_13 -> V_14 & V_21 ) {
if ( F_6 ( V_11 -> V_9 , V_13 -> V_3 ) )
F_3 ( V_6 L_8 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
V_10 = V_11 -> V_22 -> V_23 ( V_11 ) ;
if ( ( V_10 & 0x80 ) && V_11 -> V_16 && V_11 -> V_16 -> V_9 ) {
F_3 ( V_6 L_9 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - 1 ;
}
V_20:
return 0 ;
}
int F_13 ( struct V_1 * V_2 , const char * V_3 )
{
T_3 V_24 ;
F_14 ( V_2 , V_25 , & V_24 ) ;
if ( ( V_24 & V_26 ) == 0 ) {
F_15 ( V_2 ) ;
if ( F_14 ( V_2 , V_25 , & V_24 ) ||
( V_24 & V_26 ) == 0 ) {
F_3 ( V_8 L_10 ,
V_3 , F_4 ( V_2 ) ) ;
return - V_27 ;
}
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
F_3 ( V_6 L_11 ,
V_13 -> V_3 , F_4 ( V_2 ) ,
V_2 -> V_28 , V_2 -> V_29 , V_2 -> V_30 ) ;
}
static int F_17 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
int V_31 , V_32 ;
if ( F_18 ( V_2 ) ) {
V_31 = F_19 ( V_2 ) ;
if ( V_31 < 0 ) {
F_3 ( V_33 L_12 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
F_3 ( V_33 L_13 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
}
V_31 = F_20 ( V_2 , F_21 ( 32 ) ) ;
if ( V_31 < 0 ) {
F_3 ( V_8 L_14 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
if ( V_13 -> V_14 & V_34 )
V_32 = ( 1 << 2 ) - 1 ;
else
V_32 = ( 1 << 4 ) - 1 ;
if ( ( V_13 -> V_14 & V_35 ) == 0 ) {
if ( V_13 -> V_14 & V_19 )
V_32 |= ( 1 << 2 ) ;
else
V_32 |= ( 1 << 4 ) ;
}
V_31 = F_22 ( V_2 , V_32 , V_13 -> V_3 ) ;
if ( V_31 < 0 )
F_3 ( V_8 L_15 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
V_20:
return V_31 ;
}
static int F_23 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
T_3 V_24 = 0 ;
if ( F_1 ( V_2 , V_13 -> V_3 ) ||
F_24 ( V_2 , V_25 , V_24 | V_36 ) ) {
F_3 ( V_6 L_16 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_37 ;
}
if ( F_14 ( V_2 , V_25 , & V_24 ) ) {
F_3 ( V_8 L_17 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_27 ;
}
if ( ! ( V_24 & V_36 ) ) {
F_3 ( V_8 L_18 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_38 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
int V_39 )
{
T_4 V_40 = F_26 ( V_2 , V_39 ) ;
if ( ! V_40 || F_27 ( V_2 , V_39 ) == 0 )
return 0 ;
if ( V_40 & V_41 )
return 0 ;
return - V_42 ;
}
static int F_28 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
unsigned int V_43 , struct V_44 * V_45 )
{
unsigned long V_46 = 0 , V_47 = 0 ;
if ( ( V_13 -> V_14 & V_48 ) == 0 ) {
if ( F_25 ( V_2 , V_13 , 2 * V_43 ) ||
F_25 ( V_2 , V_13 , 2 * V_43 + 1 ) ) {
F_3 ( V_8 L_19
L_20 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_43 ) ;
return - V_42 ;
}
V_46 = F_11 ( V_2 , 2 * V_43 + 1 ) ;
V_47 = F_11 ( V_2 , 2 * V_43 ) ;
} else {
V_46 = V_43 ? 0x374 : 0x3f4 ;
V_47 = V_43 ? 0x170 : 0x1f0 ;
}
if ( ! V_47 || ! V_46 ) {
F_3 ( V_8 L_21 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_43 ) ;
return - V_42 ;
}
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_2 = & V_2 -> V_2 ;
F_29 ( V_45 , V_47 , V_46 | 2 ) ;
return 0 ;
}
int F_30 ( T_2 * V_11 , const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_2 ) ;
if ( ( V_13 -> V_14 & V_49 ) == 0 ||
( ( V_2 -> V_50 >> 8 ) == V_51 &&
( V_2 -> V_50 & 0x80 ) ) ) {
unsigned long V_47 = F_9 ( V_11 , V_13 ) ;
if ( V_47 == 0 )
return - 1 ;
V_11 -> V_9 = V_47 ;
if ( V_11 -> V_22 == NULL )
V_11 -> V_22 = & V_52 ;
if ( F_12 ( V_11 , V_13 ) < 0 )
return - 1 ;
if ( F_13 ( V_2 , V_13 -> V_3 ) < 0 )
return - 1 ;
if ( V_11 -> V_14 & V_15 )
F_3 ( V_6 L_22 , V_11 -> V_3 ) ;
else
F_3 ( V_6 L_23 ,
V_11 -> V_3 , V_47 , V_47 + 7 ) ;
V_11 -> V_53 = V_47 + ( V_11 -> V_17 ? 8 : 16 ) ;
if ( F_31 ( V_11 ) )
return - 1 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_12 * V_13 , int V_54 )
{
int V_31 ;
T_3 V_24 ;
if ( V_54 )
F_16 ( V_2 , V_13 ) ;
V_31 = F_17 ( V_2 , V_13 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_14 ( V_2 , V_25 , & V_24 ) ;
if ( V_31 < 0 ) {
F_3 ( V_8 L_17 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
if ( ! ( V_24 & V_36 ) ) {
V_31 = F_23 ( V_2 , V_13 ) ;
if ( V_31 < 0 )
goto V_20;
F_3 ( V_6 L_24 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
}
V_20:
return V_31 ;
}
void F_33 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
struct V_44 * V_45 , struct V_44 * * V_55 )
{
int V_56 = ( V_13 -> V_14 & V_34 ) ? 1 : 2 , V_43 ;
T_1 V_57 ;
for ( V_43 = 0 ; V_43 < V_56 ; ++ V_43 ) {
const struct V_58 * V_59 = & V_13 -> V_60 [ V_43 ] ;
if ( V_59 -> V_61 && ( F_2 ( V_2 , V_59 -> V_61 , & V_57 ) ||
( V_57 & V_59 -> V_62 ) != V_59 -> V_63 ) ) {
F_3 ( V_6 L_25 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
continue;
}
if ( F_28 ( V_2 , V_13 , V_43 , V_45 + V_43 ) )
continue;
* ( V_55 + V_43 ) = V_45 + V_43 ;
}
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
T_1 V_54 )
{
int V_64 , V_31 ;
V_64 = V_2 -> V_65 ;
V_31 = V_13 -> V_66 ? V_13 -> V_66 ( V_2 ) : 0 ;
if ( V_31 < 0 )
goto V_20;
if ( F_35 ( V_2 ) ) {
if ( V_54 )
F_3 ( V_6 L_26
L_27 , V_13 -> V_3 , F_4 ( V_2 ) ) ;
V_64 = 0 ;
} else if ( ! V_64 && V_54 ) {
F_3 ( V_33 L_28 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_64 ) ;
} else if ( V_54 ) {
F_3 ( V_6 L_29 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_64 ) ;
}
V_31 = V_64 ;
V_20:
return V_31 ;
}
int F_36 ( struct V_1 * V_67 , struct V_1 * V_68 ,
const struct V_12 * V_13 , void * V_69 )
{
struct V_1 * V_70 [] = { V_67 , V_68 } ;
struct V_71 * V_72 ;
int V_31 , V_73 , V_74 = V_68 ? 4 : 2 ;
struct V_44 V_45 [ 4 ] , * V_55 [] = { NULL , NULL , NULL , NULL } ;
for ( V_73 = 0 ; V_73 < V_74 / 2 ; V_73 ++ ) {
V_31 = F_32 ( V_70 [ V_73 ] , V_13 , ! V_73 ) ;
if ( V_31 < 0 )
goto V_20;
F_33 ( V_70 [ V_73 ] , V_13 , & V_45 [ V_73 * 2 ] , & V_55 [ V_73 * 2 ] ) ;
}
V_72 = F_37 ( V_13 , V_55 , V_74 ) ;
if ( V_72 == NULL ) {
V_31 = - V_75 ;
goto V_20;
}
V_72 -> V_2 [ 0 ] = & V_67 -> V_2 ;
if ( V_68 )
V_72 -> V_2 [ 1 ] = & V_68 -> V_2 ;
V_72 -> V_76 = V_69 ;
V_72 -> V_77 = V_78 ;
F_38 ( V_70 [ 0 ] , V_72 ) ;
if ( V_68 )
F_38 ( V_70 [ 1 ] , V_72 ) ;
for ( V_73 = 0 ; V_73 < V_74 / 2 ; V_73 ++ ) {
V_31 = F_34 ( V_70 [ V_73 ] , V_13 , ! V_73 ) ;
if ( V_31 < 0 )
goto V_20;
if ( F_35 ( V_70 [ V_73 ] ) ) {
V_45 [ V_73 * 2 ] . V_65 = F_39 ( V_70 [ V_73 ] , 0 ) ;
V_45 [ V_73 * 2 + 1 ] . V_65 = F_39 ( V_70 [ V_73 ] , 1 ) ;
} else
V_45 [ V_73 * 2 + 1 ] . V_65 = V_45 [ V_73 * 2 ] . V_65 = V_31 ;
}
V_31 = F_40 ( V_72 , V_13 , V_55 ) ;
if ( V_31 )
F_41 ( V_72 ) ;
V_20:
return V_31 ;
}
int F_42 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
void * V_69 )
{
return F_36 ( V_2 , NULL , V_13 , V_69 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_44 ( V_2 ) ;
struct V_1 * V_68 = V_72 -> V_2 [ 1 ] ? F_10 ( V_72 -> V_2 [ 1 ] ) : NULL ;
int V_32 ;
if ( V_72 -> V_14 & V_34 )
V_32 = ( 1 << 2 ) - 1 ;
else
V_32 = ( 1 << 4 ) - 1 ;
if ( ( V_72 -> V_14 & V_35 ) == 0 ) {
if ( V_72 -> V_14 & V_19 )
V_32 |= ( 1 << 2 ) ;
else
V_32 |= ( 1 << 4 ) ;
}
F_45 ( V_72 ) ;
if ( V_68 )
F_46 ( V_68 , V_32 ) ;
F_46 ( V_2 , V_32 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
F_47 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 , T_5 V_79 )
{
F_49 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 , F_51 ( V_2 , V_79 ) ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_44 ( V_2 ) ;
int V_80 ;
F_50 ( V_2 , V_81 ) ;
V_80 = F_18 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_53 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_72 -> V_66 )
V_72 -> V_66 ( V_2 ) ;
return 0 ;
}
