static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , F_3 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
V_4 , V_2 -> V_11 ,
V_2 -> V_12 , V_5 , V_13 ) ;
if ( V_6 < 0 )
F_4 ( L_1 ,
V_6 , V_3 , V_4 ) ;
return V_6 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
int V_14 , const unsigned char * V_15 , int V_16 )
{
int V_6 ;
memcpy ( V_2 -> V_12 , V_15 , V_16 ) ;
V_6 = F_2 ( V_2 -> V_7 , F_6 ( V_2 -> V_7 , 0 ) ,
V_17 ,
V_18 | V_9 | V_10 ,
V_19 , V_14 ,
V_2 -> V_12 , V_16 , V_20 ) ;
if ( V_6 >= 0 )
memcpy ( V_2 -> V_21 , V_15 , V_16 ) ;
else
F_4 ( L_2 , V_6 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_15 , int V_16 )
{
return F_2 ( V_2 -> V_7 , F_6 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_18 | V_9 | V_10 ,
V_4 , V_2 -> V_11 ,
V_15 , V_16 , V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_22 , int V_23 ,
int V_24 , int * V_25 , int V_26 )
{
int V_27 , V_28 = 0 ;
struct V_29 * V_30 ;
int V_31 [ 31 ] =
{
0 , 0 , 0 , 0 , 4 ,
5 , 5 , 7 , 7 , 10 ,
10 , 10 , 12 , 12 , 15 ,
15 , 15 , 15 , 20 , 20 ,
20 , 20 , 20 , 24 , 24 ,
24 , 24 , 24 , 24 , 24 ,
24
} ;
int V_32 [ 31 ] =
{ 0 , 0 , 0 , 0 , 0 ,
1 , 1 , 1 , 2 , 2 ,
3 , 3 , 4 , 4 , 4 ,
5 , 5 , 5 , 5 , 5 ,
6 , 6 , 6 , 6 , 7 ,
7 , 7 , 7 , 7 , 7 ,
7
} ;
if ( V_22 < 0 || V_22 > V_33 )
return - V_34 ;
if ( V_24 < 4 )
V_24 = 4 ;
else if ( V_24 > 25 )
V_24 = 25 ;
V_24 = V_31 [ V_24 ] ;
V_27 = V_32 [ V_24 ] ;
V_30 = & V_35 [ V_22 ] [ V_27 ] ;
if ( V_30 -> V_36 == 0 )
return - V_34 ;
if ( V_26 )
V_28 = F_5 ( V_2 , V_2 -> V_37 ,
V_30 -> V_38 , 3 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_30 -> V_39 && V_23 == V_40 )
F_9 ( V_2 , V_30 -> V_38 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_41 = V_24 ;
V_2 -> V_42 = V_30 -> V_36 ;
V_2 -> V_43 = V_44 [ V_22 ] [ 0 ] ;
V_2 -> V_45 = V_44 [ V_22 ] [ 1 ] ;
V_2 -> V_46 = ( V_2 -> V_43 * V_2 -> V_45 * 3 ) / 2 ;
if ( V_30 -> V_39 ) {
if ( V_2 -> V_47 < 5 ) {
V_2 -> V_48 = 528 ;
V_2 -> V_46 /= 4 ;
}
else {
V_2 -> V_48 = 704 ;
V_2 -> V_46 /= 3 ;
}
}
else
V_2 -> V_48 = 0 ;
* V_25 = 3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 , int V_23 ,
int V_24 , int * V_25 , int V_26 )
{
const struct V_49 * V_50 ;
int V_27 , V_28 = 0 ;
if ( V_22 >= V_51 || * V_25 < 0 || * V_25 > 3 )
return - V_34 ;
if ( V_24 < 5 )
V_24 = 5 ;
else if ( V_22 == V_52 && V_24 > 15 )
V_24 = 15 ;
else if ( V_24 > 30 )
V_24 = 30 ;
V_27 = ( V_24 / 5 ) - 1 ;
V_50 = NULL ;
while ( * V_25 <= 3 ) {
V_50 = & V_53 [ V_22 ] [ V_27 ] [ * V_25 ] ;
if ( V_50 -> V_36 != 0 )
break;
( * V_25 ) ++ ;
}
if ( V_50 == NULL || V_50 -> V_36 == 0 )
return - V_54 ;
if ( V_26 )
V_28 = F_5 ( V_2 , V_2 -> V_37 ,
V_50 -> V_38 , 13 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_50 -> V_55 > 0 && V_23 == V_40 )
F_11 ( V_2 , V_50 -> V_38 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_41 = ( V_27 + 1 ) * 5 ;
V_2 -> V_42 = V_50 -> V_36 ;
V_2 -> V_43 = V_44 [ V_22 ] [ 0 ] ;
V_2 -> V_45 = V_44 [ V_22 ] [ 1 ] ;
V_2 -> V_48 = V_50 -> V_55 ;
if ( V_50 -> V_55 > 0 )
V_2 -> V_46 = ( V_50 -> V_55 * V_2 -> V_45 ) / 4 ;
else
V_2 -> V_46 = ( V_2 -> V_43 * V_2 -> V_45 * 12 ) / 8 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_22 , int V_23 ,
int V_24 , int * V_25 , int V_26 )
{
const struct V_56 * V_50 = NULL ;
int V_27 , V_28 = 0 ;
if ( V_22 >= V_51 || * V_25 < 0 || * V_25 > 3 )
return - V_34 ;
if ( V_24 < 5 )
V_24 = 5 ;
else if ( V_22 == V_52 && V_24 > 15 )
V_24 = 15 ;
else if ( V_24 > 30 )
V_24 = 30 ;
V_27 = ( V_24 / 5 ) - 1 ;
while ( * V_25 <= 3 ) {
V_50 = & V_57 [ V_22 ] [ V_27 ] [ * V_25 ] ;
if ( V_50 -> V_36 != 0 )
break;
( * V_25 ) ++ ;
}
if ( V_50 == NULL || V_50 -> V_36 == 0 )
return - V_54 ;
if ( V_26 )
V_28 = F_5 ( V_2 , 4 , V_50 -> V_38 , 12 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_50 -> V_55 > 0 && V_23 == V_40 )
F_11 ( V_2 , V_50 -> V_38 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_41 = ( V_27 + 1 ) * 5 ;
V_2 -> V_42 = V_50 -> V_36 ;
V_2 -> V_43 = V_44 [ V_22 ] [ 0 ] ;
V_2 -> V_45 = V_44 [ V_22 ] [ 1 ] ;
V_2 -> V_48 = V_50 -> V_55 ;
if ( V_2 -> V_48 > 0 )
V_2 -> V_46 = ( V_2 -> V_48 * V_2 -> V_45 ) / 4 ;
else
V_2 -> V_46 = ( V_2 -> V_43 * V_2 -> V_45 * 12 ) / 8 ;
F_13 ( L_3 ,
V_2 -> V_46 , V_2 -> V_41 , V_22 , V_2 -> V_48 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_43 , int V_45 ,
int V_23 , int V_24 , int * V_25 , int V_26 )
{
int V_28 , V_22 ;
F_15 ( L_4 ,
V_43 , V_45 , V_24 , V_23 ) ;
V_22 = F_16 ( V_2 , V_43 , V_45 ) ;
F_13 ( L_5 , V_22 ) ;
if ( F_17 ( V_2 -> type ) ) {
V_28 = F_8 ( V_2 , V_22 , V_23 , V_24 ,
V_25 , V_26 ) ;
} else if ( F_18 ( V_2 -> type ) ) {
V_28 = F_12 ( V_2 , V_22 , V_23 , V_24 ,
V_25 , V_26 ) ;
} else {
V_28 = F_10 ( V_2 , V_22 , V_23 , V_24 ,
V_25 , V_26 ) ;
}
if ( V_28 < 0 ) {
F_4 ( L_6 , V_58 [ V_22 ] , V_24 , V_28 ) ;
return V_28 ;
}
V_2 -> V_59 = V_2 -> V_46 + V_2 -> V_60 + V_2 -> V_61 ;
F_19 ( L_7 , V_2 -> V_43 , V_2 -> V_45 ) ;
return 0 ;
}
static unsigned int F_20 ( struct V_1 * V_2 , unsigned int V_14 , unsigned int V_22 )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
if ( V_35 [ V_22 ] [ V_62 ] . V_36 ) {
if ( V_14 -- == 0 ) return V_64 [ V_62 ] ;
}
}
return 0 ;
}
static unsigned int F_21 ( struct V_1 * V_2 , unsigned int V_14 , unsigned int V_22 )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
if ( V_57 [ V_22 ] [ V_62 ] [ 3 ] . V_36 ) {
if ( V_14 -- == 0 ) return V_66 [ V_62 ] ;
}
}
return 0 ;
}
static unsigned int F_22 ( struct V_1 * V_2 , unsigned int V_14 , unsigned int V_22 )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_67 ; V_62 ++ ) {
if ( V_53 [ V_22 ] [ V_62 ] [ 3 ] . V_36 ) {
if ( V_14 -- == 0 ) return V_68 [ V_62 ] ;
}
}
return 0 ;
}
unsigned int F_23 ( struct V_1 * V_2 , unsigned int V_14 , unsigned int V_22 )
{
unsigned int V_28 ;
if ( F_17 ( V_2 -> type ) ) {
V_28 = F_20 ( V_2 , V_14 , V_22 ) ;
} else if ( F_18 ( V_2 -> type ) ) {
V_28 = F_21 ( V_2 , V_14 , V_22 ) ;
} else {
V_28 = F_22 ( V_2 , V_14 , V_22 ) ;
}
return V_28 ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_69 )
{
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_4 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
* V_69 = V_2 -> V_12 [ 0 ] ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_1 V_69 )
{
int V_28 ;
V_2 -> V_12 [ 0 ] = V_69 ;
V_28 = F_7 ( V_2 , V_3 , V_4 , V_2 -> V_12 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_69 )
{
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_4 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
* V_69 = ( ( V_70 * ) V_2 -> V_12 ) [ 0 ] ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , int * V_69 )
{
int V_28 ;
V_28 = F_1 ( V_2 , V_3 , V_4 , 2 ) ;
if ( V_28 < 0 )
return V_28 ;
* V_69 = ( V_2 -> V_12 [ 1 ] << 8 ) | V_2 -> V_12 [ 0 ] ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_69 )
{
int V_28 ;
V_2 -> V_12 [ 0 ] = V_69 & 0xff ;
V_2 -> V_12 [ 1 ] = V_69 >> 8 ;
V_28 = F_7 ( V_2 , V_3 , V_4 , V_2 -> V_12 , 2 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , T_2 V_4 )
{
int V_28 ;
V_28 = F_7 ( V_2 , V_71 , V_4 , NULL , 0 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 , int V_72 )
{
int V_73 ;
if ( ! V_2 -> V_74 )
return;
if ( V_2 -> type < 675 || ( V_2 -> type < 730 && V_2 -> V_47 < 6 ) )
return;
if ( V_72 )
V_2 -> V_12 [ 0 ] = 0x00 ;
else
V_2 -> V_12 [ 0 ] = 0xFF ;
V_73 = F_7 ( V_2 , V_71 ,
V_75 , V_2 -> V_12 , 1 ) ;
if ( V_73 < 0 )
F_4 ( L_8 ,
V_72 ? L_9 : L_10 , V_73 ) ;
}
int F_31 ( struct V_1 * V_2 , int V_76 , int V_77 )
{
int V_73 ;
if ( V_2 -> type < 730 )
return 0 ;
V_76 /= 100 ;
V_77 /= 100 ;
if ( V_76 < 0 )
V_76 = 0 ;
if ( V_76 > 0xff )
V_76 = 0xff ;
if ( V_77 < 0 )
V_77 = 0 ;
if ( V_77 > 0xff )
V_77 = 0xff ;
V_2 -> V_12 [ 0 ] = V_76 ;
V_2 -> V_12 [ 1 ] = V_77 ;
V_73 = F_7 ( V_2 ,
V_71 , V_78 , V_2 -> V_12 , 2 ) ;
if ( V_73 < 0 )
F_4 ( L_11 , V_73 ) ;
return V_73 ;
}
int F_32 ( struct V_1 * V_2 , int * V_79 )
{
int V_28 = - 1 , V_3 ;
if ( V_2 -> type < 675 )
V_3 = V_80 ;
else if ( V_2 -> type < 730 )
return - 1 ;
else
V_3 = V_81 ;
V_28 = F_1 ( V_2 , V_82 , V_3 , 1 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_2 -> type < 675 )
* V_79 = V_2 -> V_12 [ 0 ] | 0x100 ;
else
* V_79 = V_2 -> V_12 [ 0 ] ;
return 0 ;
}
