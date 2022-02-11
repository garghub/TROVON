static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_11 ) |
( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_12 ) ) {
F_3 ( & V_7 -> V_13 -> V_14 , L_1 ) ;
return 0 ;
}
V_5 = F_4 ( V_7 -> V_15 , & V_4 , 1 ,
V_16 [ V_9 [ V_3 ] ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_13 -> V_14 , L_2 ) ;
return 0 ;
}
if ( V_4 & V_17 [ V_3 ] ) {
if ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 != V_18 )
return 0 ;
return 1 ;
}
if ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 != V_18 )
return 1 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_19 )
{
T_1 V_4 ;
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_20 ) |
( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_12 ) ) {
F_3 ( & V_7 -> V_13 -> V_14 , L_3 ) ;
return;
}
if ( V_19 )
V_4 = V_7 -> V_8 [ V_9 [ V_3 ] ] . V_19 |
V_17 [ V_3 ] ;
else
V_4 = V_7 -> V_8 [ V_9 [ V_3 ] ] . V_19 &
~ V_17 [ V_3 ] ;
V_5 = F_6 ( V_7 -> V_15 , & V_4 , 1 ,
V_16 [ V_9 [ V_3 ] ] ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_13 -> V_14 , L_4 ) ;
return;
}
V_7 -> V_8 [ V_9 [ V_3 ] ] . V_19 = V_4 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_11 ) |
( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_12 ) ) {
F_3 ( & V_7 -> V_13 -> V_14 ,
L_5 ) ;
V_21 = - V_22 ;
} else {
V_21 = 0 ;
}
return V_21 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_19 )
{
int V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_20 ) |
( V_7 -> V_8 [ V_9 [ V_3 ] ] . V_10 == V_12 ) ) {
F_3 ( & V_7 -> V_13 -> V_14 ,
L_5 ) ;
V_21 = - V_22 ;
} else {
V_21 = 0 ;
}
return V_21 ;
}
int F_9 ( struct V_6 * V_7 )
{
int V_5 = 0 ;
int V_23 , V_24 ;
T_1 V_21 = 0 ;
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_5 = F_6 ( V_7 -> V_15 , & V_21 , 1 ,
V_16 [ V_23 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_7 -> V_8 [ V_23 ] . V_19 = 0 ;
}
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
V_5 = F_6 ( V_7 -> V_15 , & V_21 , 1 ,
V_25 [ V_23 * 2 ] ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_7 -> V_15 , & V_21 , 1 ,
V_25 [ ( V_23 * 2 ) + 1 ] ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ )
V_7 -> V_8 [ V_23 ] . V_26 [ V_24 ] = V_27 ;
}
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ ) {
do {
V_5 = F_4 ( V_7 -> V_15 , & V_21 , 1 ,
V_28 [ V_23 ] ) ;
if ( V_5 < 0 )
return V_5 ;
} while ( V_21 != 0 );
}
return 0 ;
}
int F_10 ( struct V_6 * V_7 )
{
int V_5 = 0 ;
char * V_29 ;
V_29 = F_11 ( V_30 ,
L_6 , V_31 , F_12 ( & V_7 -> V_13 -> V_14 ) ) ;
if ( ! V_29 )
return - V_32 ;
V_7 -> V_33 . V_29 = V_29 ;
V_7 -> V_33 . V_34 = V_35 ;
V_7 -> V_33 . V_36 = - 1 ;
V_7 -> V_33 . V_37 = F_7 ;
V_7 -> V_33 . V_38 = F_8 ;
V_7 -> V_33 . V_39 = F_1 ;
V_7 -> V_33 . V_40 = F_5 ;
V_5 = F_13 ( & V_7 -> V_33 , V_7 ) ;
if ( V_5 ) {
F_3 ( & V_7 -> V_13 -> V_14 , L_7 ) ;
F_14 ( V_7 -> V_33 . V_29 ) ;
}
return V_5 ;
}
void F_15 ( struct V_6 * V_7 )
{
const char * V_29 = V_7 -> V_33 . V_29 ;
F_16 ( & V_7 -> V_33 ) ;
F_14 ( V_29 ) ;
}
