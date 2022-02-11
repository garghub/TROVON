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
static int F_17 ( struct V_1 * V_2 , int V_31 ,
const struct V_12 * V_13 )
{
int V_32 ;
if ( F_18 ( V_2 ) ) {
V_32 = F_19 ( V_2 ) ;
if ( V_32 < 0 ) {
F_3 ( V_33 L_12 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
F_3 ( V_33 L_13 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
}
V_32 = F_20 ( & V_2 -> V_2 , F_21 ( 32 ) ) ;
if ( V_32 < 0 ) {
F_3 ( V_8 L_14 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_20;
}
V_32 = F_22 ( V_2 , V_31 , V_13 -> V_3 ) ;
if ( V_32 < 0 )
F_3 ( V_8 L_15 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
V_20:
return V_32 ;
}
static int F_23 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
T_3 V_24 = 0 ;
if ( F_1 ( V_2 , V_13 -> V_3 ) ||
F_24 ( V_2 , V_25 , V_24 | V_34 ) ) {
F_3 ( V_6 L_16 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_35 ;
}
if ( F_14 ( V_2 , V_25 , & V_24 ) ) {
F_3 ( V_8 L_17 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_27 ;
}
if ( ! ( V_24 & V_34 ) ) {
F_3 ( V_8 L_18 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
return - V_36 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
int V_37 )
{
T_4 V_38 = F_26 ( V_2 , V_37 ) ;
if ( ! V_38 || F_27 ( V_2 , V_37 ) == 0 )
return 0 ;
if ( V_38 & V_39 )
return 0 ;
return - V_40 ;
}
static int F_28 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
unsigned int V_41 , struct V_42 * V_43 )
{
unsigned long V_44 = 0 , V_45 = 0 ;
if ( ( V_13 -> V_14 & V_46 ) == 0 ) {
if ( F_25 ( V_2 , V_13 , 2 * V_41 ) ||
F_25 ( V_2 , V_13 , 2 * V_41 + 1 ) ) {
F_3 ( V_8 L_19
L_20 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_41 ) ;
return - V_40 ;
}
V_44 = F_11 ( V_2 , 2 * V_41 + 1 ) ;
V_45 = F_11 ( V_2 , 2 * V_41 ) ;
} else {
V_44 = V_41 ? 0x374 : 0x3f4 ;
V_45 = V_41 ? 0x170 : 0x1f0 ;
}
if ( ! V_45 || ! V_44 ) {
F_3 ( V_8 L_21 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_41 ) ;
return - V_40 ;
}
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_2 = & V_2 -> V_2 ;
F_29 ( V_43 , V_45 , V_44 | 2 ) ;
return 0 ;
}
int F_30 ( T_2 * V_11 , const struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_11 -> V_2 ) ;
if ( ( V_13 -> V_14 & V_47 ) == 0 ||
( ( V_2 -> V_48 >> 8 ) == V_49 &&
( V_2 -> V_48 & 0x80 ) ) ) {
unsigned long V_45 = F_9 ( V_11 , V_13 ) ;
if ( V_45 == 0 )
return - 1 ;
V_11 -> V_9 = V_45 ;
if ( V_11 -> V_22 == NULL )
V_11 -> V_22 = & V_50 ;
if ( F_12 ( V_11 , V_13 ) < 0 )
return - 1 ;
if ( F_13 ( V_2 , V_13 -> V_3 ) < 0 )
return - 1 ;
if ( V_11 -> V_14 & V_15 )
F_3 ( V_6 L_22 , V_11 -> V_3 ) ;
else
F_3 ( V_6 L_23 ,
V_11 -> V_3 , V_45 , V_45 + 7 ) ;
V_11 -> V_51 = V_45 + ( V_11 -> V_17 ? 8 : 16 ) ;
if ( F_31 ( V_11 ) )
return - 1 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , int V_31 ,
const struct V_12 * V_13 , int V_52 )
{
int V_32 ;
T_3 V_24 ;
if ( V_52 )
F_16 ( V_2 , V_13 ) ;
V_32 = F_17 ( V_2 , V_31 , V_13 ) ;
if ( V_32 < 0 )
goto V_20;
V_32 = F_14 ( V_2 , V_25 , & V_24 ) ;
if ( V_32 < 0 ) {
F_3 ( V_8 L_17 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
goto V_53;
}
if ( ! ( V_24 & V_34 ) ) {
V_32 = F_23 ( V_2 , V_13 ) ;
if ( V_32 < 0 )
goto V_53;
F_3 ( V_6 L_24 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
}
goto V_20;
V_53:
F_33 ( V_2 , V_31 ) ;
V_20:
return V_32 ;
}
void F_34 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
struct V_42 * V_43 , struct V_42 * * V_54 )
{
int V_55 = ( V_13 -> V_14 & V_56 ) ? 1 : 2 , V_41 ;
T_1 V_57 ;
for ( V_41 = 0 ; V_41 < V_55 ; ++ V_41 ) {
const struct V_58 * V_59 = & V_13 -> V_60 [ V_41 ] ;
if ( V_59 -> V_61 && ( F_2 ( V_2 , V_59 -> V_61 , & V_57 ) ||
( V_57 & V_59 -> V_62 ) != V_59 -> V_63 ) ) {
F_3 ( V_6 L_25 ,
V_13 -> V_3 , F_4 ( V_2 ) ) ;
continue;
}
if ( F_28 ( V_2 , V_13 , V_41 , V_43 + V_41 ) )
continue;
* ( V_54 + V_41 ) = V_43 + V_41 ;
}
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
T_1 V_52 )
{
int V_64 , V_32 ;
V_64 = V_2 -> V_65 ;
V_32 = V_13 -> V_66 ? V_13 -> V_66 ( V_2 ) : 0 ;
if ( V_32 < 0 )
goto V_20;
if ( F_36 ( V_2 ) ) {
if ( V_52 )
F_3 ( V_6 L_26
L_27 , V_13 -> V_3 , F_4 ( V_2 ) ) ;
V_64 = 0 ;
} else if ( ! V_64 && V_52 ) {
F_3 ( V_33 L_28 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_64 ) ;
} else if ( V_52 ) {
F_3 ( V_6 L_29 ,
V_13 -> V_3 , F_4 ( V_2 ) , V_64 ) ;
}
V_32 = V_64 ;
V_20:
return V_32 ;
}
int F_37 ( struct V_1 * V_67 , struct V_1 * V_68 ,
const struct V_12 * V_13 , void * V_69 )
{
struct V_1 * V_70 [] = { V_67 , V_68 } ;
struct V_71 * V_72 ;
int V_32 , V_73 , V_74 = V_68 ? 4 : 2 , V_31 ;
struct V_42 V_43 [ 4 ] , * V_54 [] = { NULL , NULL , NULL , NULL } ;
if ( V_13 -> V_14 & V_56 )
V_31 = ( 1 << 2 ) - 1 ;
else
V_31 = ( 1 << 4 ) - 1 ;
if ( ( V_13 -> V_14 & V_75 ) == 0 ) {
if ( V_13 -> V_14 & V_19 )
V_31 |= ( 1 << 2 ) ;
else
V_31 |= ( 1 << 4 ) ;
}
for ( V_73 = 0 ; V_73 < V_74 / 2 ; V_73 ++ ) {
V_32 = F_32 ( V_70 [ V_73 ] , V_31 , V_13 , ! V_73 ) ;
if ( V_32 < 0 ) {
if ( V_73 == 1 )
F_33 ( V_70 [ 0 ] , V_31 ) ;
goto V_20;
}
F_34 ( V_70 [ V_73 ] , V_13 , & V_43 [ V_73 * 2 ] , & V_54 [ V_73 * 2 ] ) ;
}
V_72 = F_38 ( V_13 , V_54 , V_74 ) ;
if ( V_72 == NULL ) {
V_32 = - V_76 ;
goto V_53;
}
V_72 -> V_2 [ 0 ] = & V_67 -> V_2 ;
if ( V_68 )
V_72 -> V_2 [ 1 ] = & V_68 -> V_2 ;
V_72 -> V_77 = V_69 ;
V_72 -> V_78 = V_79 ;
F_39 ( V_70 [ 0 ] , V_72 ) ;
if ( V_68 )
F_39 ( V_70 [ 1 ] , V_72 ) ;
for ( V_73 = 0 ; V_73 < V_74 / 2 ; V_73 ++ ) {
V_32 = F_35 ( V_70 [ V_73 ] , V_13 , ! V_73 ) ;
if ( V_32 < 0 )
goto V_53;
if ( F_36 ( V_70 [ V_73 ] ) ) {
V_43 [ V_73 * 2 ] . V_65 = F_40 ( V_70 [ V_73 ] , 0 ) ;
V_43 [ V_73 * 2 + 1 ] . V_65 = F_40 ( V_70 [ V_73 ] , 1 ) ;
} else
V_43 [ V_73 * 2 + 1 ] . V_65 = V_43 [ V_73 * 2 ] . V_65 = V_32 ;
}
V_32 = F_41 ( V_72 , V_13 , V_54 ) ;
if ( V_32 )
F_42 ( V_72 ) ;
else
goto V_20;
V_53:
V_73 = V_74 / 2 ;
while ( V_73 -- )
F_33 ( V_70 [ V_73 ] , V_31 ) ;
V_20:
return V_32 ;
}
int F_43 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
void * V_69 )
{
return F_37 ( V_2 , NULL , V_13 , V_69 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_45 ( V_2 ) ;
struct V_1 * V_68 = V_72 -> V_2 [ 1 ] ? F_10 ( V_72 -> V_2 [ 1 ] ) : NULL ;
int V_31 ;
if ( V_72 -> V_14 & V_56 )
V_31 = ( 1 << 2 ) - 1 ;
else
V_31 = ( 1 << 4 ) - 1 ;
if ( ( V_72 -> V_14 & V_75 ) == 0 ) {
if ( V_72 -> V_14 & V_19 )
V_31 |= ( 1 << 2 ) ;
else
V_31 |= ( 1 << 4 ) ;
}
F_46 ( V_72 ) ;
if ( V_68 )
F_33 ( V_68 , V_31 ) ;
F_33 ( V_2 , V_31 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
F_47 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 , T_5 V_80 )
{
F_49 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 , F_51 ( V_2 , V_80 ) ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_45 ( V_2 ) ;
int V_81 ;
F_50 ( V_2 , V_82 ) ;
V_81 = F_18 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_53 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_72 -> V_66 )
V_72 -> V_66 ( V_2 ) ;
return 0 ;
}
