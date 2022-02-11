int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( ! V_4 [ V_3 ] ) {
V_4 [ V_3 ] = V_2 ;
return 0 ;
}
}
return - V_5 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] == V_2 ) {
V_4 [ V_3 ] = NULL ;
return;
}
}
}
struct V_1 * F_4 ( const char * V_6 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] && strcmp ( V_4 [ V_3 ] -> V_6 , V_6 ) == 0 )
return V_4 [ V_3 ] ;
}
return NULL ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_6 ( V_2 -> V_8 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_9 ) {
V_7 = F_7 ( V_2 -> V_9 ) ;
if ( V_7 )
goto V_10;
}
V_7 = V_2 -> V_11 -> V_12 ( V_2 ) ;
if ( V_7 )
goto V_13;
return 0 ;
V_13:
if ( V_2 -> V_9 )
F_8 ( V_2 -> V_9 ) ;
V_10:
F_9 ( V_2 -> V_8 ) ;
return V_7 ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_11 -> V_14 ( V_2 ) ;
if ( V_2 -> V_9 )
F_8 ( V_2 -> V_9 ) ;
F_9 ( V_2 -> V_8 ) ;
memset ( & V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
}
int F_11 ( struct V_1 * V_2 , const struct V_16 * V_15 )
{
int V_7 ;
V_7 = V_2 -> V_11 -> V_17 ( V_2 , V_15 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_15 = * V_15 ;
return 0 ;
}
bool F_12 ( const struct V_1 * V_2 , unsigned long V_18 ,
unsigned long V_19 , unsigned long V_20 ,
T_1 V_21 , void * V_22 )
{
const struct V_23 * V_24 = V_2 -> V_24 ;
int V_25 , V_26 , V_27 ;
unsigned long V_28 ;
V_19 = V_19 ? V_19 : 1 ;
V_20 = V_20 ? V_20 : V_29 ;
V_26 = F_13 ( F_14 ( V_18 , V_20 ) , 1ul ) ;
V_27 = F_15 ( ( unsigned ) ( V_18 / V_19 ) , V_24 -> V_30 ) ;
for ( V_25 = V_26 ; V_25 <= V_27 ; ++ V_25 ) {
V_28 = V_18 / V_25 ;
if ( V_21 ( V_25 , V_28 , V_22 ) )
return true ;
}
return false ;
}
bool F_16 ( const struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_31 , unsigned long V_32 ,
T_2 V_21 , void * V_22 )
{
const struct V_23 * V_24 = V_2 -> V_24 ;
int V_33 , V_34 , V_35 ;
int V_25 , V_26 , V_27 ;
unsigned long V_36 , V_18 ;
unsigned long V_37 ;
unsigned long V_38 , V_39 ;
V_37 = V_24 -> V_40 ;
V_38 = V_24 -> V_41 ;
V_39 = V_24 -> V_42 ;
V_34 = F_13 ( F_14 ( V_8 , V_39 ) , 1ul ) ;
V_35 = F_15 ( ( unsigned ) ( V_8 / V_38 ) , V_24 -> V_43 ) ;
V_32 = V_32 ? V_32 : V_29 ;
for ( V_33 = V_34 ; V_33 <= V_35 ; ++ V_33 ) {
V_36 = V_8 / V_33 ;
V_26 = F_13 ( F_14 ( F_14 ( V_31 , V_36 ) , 2 ) ,
1ul ) ;
V_27 = F_17 ( ( unsigned ) ( V_32 / V_36 / 2 ) ,
( unsigned ) ( V_37 / V_36 / 2 ) ,
V_24 -> V_44 ) ;
for ( V_25 = V_26 ; V_25 <= V_27 ; ++ V_25 ) {
V_18 = 2 * V_25 * V_36 ;
if ( V_21 ( V_33 , V_25 , V_36 , V_18 , V_22 ) )
return true ;
}
}
return false ;
}
static int F_18 ( void T_3 * V_45 , int V_46 , int V_47 )
{
unsigned long V_48 ;
T_4 V_49 ;
int V_50 ;
V_50 = 100 ;
while ( V_50 -- > 0 ) {
if ( F_19 ( F_20 ( V_45 ) , V_46 , V_46 ) == V_47 )
return V_47 ;
}
V_48 = V_51 + F_21 ( 500 ) ;
while ( F_22 ( V_51 , V_48 ) ) {
if ( F_19 ( F_20 ( V_45 ) , V_46 , V_46 ) == V_47 )
return V_47 ;
V_49 = F_23 ( 1000 * 1000 ) ;
F_24 ( V_52 ) ;
F_25 ( & V_49 , V_53 ) ;
}
return ! V_47 ;
}
int F_26 ( struct V_1 * V_2 )
{
void T_3 * V_54 = V_2 -> V_54 ;
if ( F_18 ( V_54 + V_55 , 0 , 1 ) != 1 )
return - V_56 ;
else
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_5 V_57 )
{
int V_50 = 100 ;
while ( V_50 -- > 0 ) {
T_5 V_58 = F_20 ( V_2 -> V_54 + V_55 ) ;
V_58 &= V_57 ;
if ( V_58 == V_57 )
return 0 ;
}
return - V_56 ;
}
int F_28 ( struct V_1 * V_2 ,
const struct V_16 * V_15 )
{
const struct V_23 * V_24 = V_2 -> V_24 ;
void T_3 * V_54 = V_2 -> V_54 ;
int V_7 = 0 ;
T_5 V_59 ;
V_59 = 0 ;
if ( V_24 -> V_60 )
V_59 = F_29 ( V_59 , 1 , 0 , 0 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_33 - 1 , V_24 -> V_61 , V_24 -> V_62 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_25 , V_24 -> V_63 , V_24 -> V_64 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 0 ] ? V_15 -> V_65 [ 0 ] - 1 : 0 ,
V_24 -> V_66 [ 0 ] , V_24 -> V_67 [ 0 ] ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 1 ] ? V_15 -> V_65 [ 1 ] - 1 : 0 ,
V_24 -> V_66 [ 1 ] , V_24 -> V_67 [ 1 ] ) ;
F_30 ( V_59 , V_54 + V_68 ) ;
V_59 = 0 ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 2 ] ? V_15 -> V_65 [ 2 ] - 1 : 0 ,
V_24 -> V_66 [ 2 ] , V_24 -> V_67 [ 2 ] ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 3 ] ? V_15 -> V_65 [ 3 ] - 1 : 0 ,
V_24 -> V_66 [ 3 ] , V_24 -> V_67 [ 3 ] ) ;
F_30 ( V_59 , V_54 + V_69 ) ;
V_59 = F_20 ( V_54 + V_70 ) ;
if ( V_24 -> V_71 ) {
T_5 V_72 = V_15 -> V_36 < 1000000 ? 0x3 :
V_15 -> V_36 < 1250000 ? 0x4 :
V_15 -> V_36 < 1500000 ? 0x5 :
V_15 -> V_36 < 1750000 ? 0x6 :
0x7 ;
V_59 = F_29 ( V_59 , V_72 , 4 , 1 ) ;
} else if ( V_24 -> V_73 ) {
T_5 V_72 = V_15 -> V_18 < V_24 -> V_74 ? 0x2 : 0x4 ;
V_59 = F_29 ( V_59 , V_72 , 3 , 1 ) ;
}
V_59 = F_29 ( V_59 , 1 , 13 , 13 ) ;
V_59 = F_29 ( V_59 , 0 , 14 , 14 ) ;
V_59 = F_29 ( V_59 , 0 , 16 , 16 ) ;
V_59 = F_29 ( V_59 , 0 , 18 , 18 ) ;
V_59 = F_29 ( V_59 , 1 , 20 , 20 ) ;
if ( V_24 -> V_75 )
V_59 = F_29 ( V_59 , 3 , 22 , 21 ) ;
V_59 = F_29 ( V_59 , 0 , 23 , 23 ) ;
V_59 = F_29 ( V_59 , 0 , 25 , 25 ) ;
F_30 ( V_59 , V_54 + V_70 ) ;
F_30 ( 1 , V_54 + V_76 ) ;
if ( F_18 ( V_54 + V_76 , 0 , 0 ) != 0 ) {
F_31 ( L_1 ) ;
V_7 = - V_77 ;
goto V_78;
}
if ( F_18 ( V_54 + V_55 , 1 , 1 ) != 1 ) {
F_31 ( L_2 ) ;
V_7 = - V_77 ;
goto V_78;
}
V_59 = F_20 ( V_54 + V_70 ) ;
V_59 = F_29 ( V_59 , 1 , 14 , 14 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 0 ] ? 1 : 0 , 16 , 16 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 1 ] ? 1 : 0 , 18 , 18 ) ;
V_59 = F_29 ( V_59 , 0 , 20 , 20 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 2 ] ? 1 : 0 , 23 , 23 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 3 ] ? 1 : 0 , 25 , 25 ) ;
F_30 ( V_59 , V_54 + V_70 ) ;
V_7 = F_27 ( V_2 ,
( V_15 -> V_65 [ 0 ] ? F_32 ( 7 ) : 0 ) |
( V_15 -> V_65 [ 1 ] ? F_32 ( 8 ) : 0 ) |
( V_15 -> V_65 [ 2 ] ? F_32 ( 10 ) : 0 ) |
( V_15 -> V_65 [ 3 ] ? F_32 ( 11 ) : 0 ) ) ;
if ( V_7 ) {
F_31 ( L_3 ) ;
goto V_78;
}
V_78:
return V_7 ;
}
int F_33 ( struct V_1 * V_2 ,
const struct V_16 * V_15 )
{
const struct V_23 * V_24 = V_2 -> V_24 ;
void T_3 * V_54 = V_2 -> V_54 ;
T_5 V_59 ;
V_59 = 0 ;
V_59 = F_29 ( V_59 , V_15 -> V_25 , 20 , 9 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_33 - 1 , 8 , 1 ) ;
F_30 ( V_59 , V_54 + V_68 ) ;
V_59 = F_20 ( V_54 + V_70 ) ;
V_59 = F_29 ( V_59 , 0x0 , 12 , 12 ) ;
V_59 = F_29 ( V_59 , 0x1 , 13 , 13 ) ;
V_59 = F_29 ( V_59 , 0x0 , 14 , 14 ) ;
if ( V_24 -> V_75 )
V_59 = F_29 ( V_59 , 0x3 , 22 , 21 ) ;
if ( V_15 -> V_18 > V_24 -> V_74 )
V_59 = F_29 ( V_59 , 0x4 , 3 , 1 ) ;
else
V_59 = F_29 ( V_59 , 0x2 , 3 , 1 ) ;
F_30 ( V_59 , V_54 + V_70 ) ;
V_59 = F_20 ( V_54 + V_69 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_79 , 17 , 10 ) ;
F_30 ( V_59 , V_54 + V_69 ) ;
V_59 = F_20 ( V_54 + V_80 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_65 [ 0 ] , 24 , 18 ) ;
V_59 = F_29 ( V_59 , V_15 -> V_81 , 17 , 0 ) ;
F_30 ( V_59 , V_54 + V_80 ) ;
F_30 ( 1 , V_54 + V_76 ) ;
if ( F_18 ( V_54 + V_76 , 0 , 0 ) != 0 ) {
F_31 ( L_1 ) ;
return - V_77 ;
}
if ( F_18 ( V_54 + V_55 , 1 , 1 ) != 1 ) {
F_31 ( L_2 ) ;
return - V_56 ;
}
return 0 ;
}
