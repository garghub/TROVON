static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned int V_5 )
{
T_1 V_6 ;
int V_7 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_12 ) |
( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_13 ) ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_1 ) ;
return 0 ;
}
V_7 = F_5 ( V_8 -> V_16 , & V_6 , 1 ,
V_17 [ V_10 [ V_5 ] ] ) ;
if ( V_7 < 0 ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_2 ) ;
return 0 ;
}
if ( V_6 & V_18 [ V_5 ] ) {
if ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 != V_19 )
return 0 ;
else
return 1 ;
} else {
if ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 != V_19 )
return 1 ;
else
return 0 ;
}
}
static void F_6 ( struct V_2 * V_3 , unsigned int V_5 ,
int V_20 )
{
T_1 V_6 ;
int V_7 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_21 ) |
( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_13 ) ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_3 ) ;
return;
}
if ( V_20 )
V_6 = V_8 -> V_9 [ V_10 [ V_5 ] ] . V_20 |
V_18 [ V_5 ] ;
else
V_6 = V_8 -> V_9 [ V_10 [ V_5 ] ] . V_20 &
~ V_18 [ V_5 ] ;
V_7 = F_7 ( V_8 -> V_16 , & V_6 , 1 ,
V_17 [ V_10 [ V_5 ] ] ) ;
if ( V_7 < 0 ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_4 ) ;
return;
}
V_8 -> V_9 [ V_10 [ V_5 ] ] . V_20 = V_6 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned V_5 )
{
int V_22 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_12 ) |
( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_13 ) ) {
F_4 ( & V_8 -> V_14 -> V_15 ,
L_5 ) ;
V_22 = - V_23 ;
} else {
V_22 = 0 ;
}
return V_22 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_5 , int V_20 )
{
int V_22 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( ( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_21 ) |
( V_8 -> V_9 [ V_10 [ V_5 ] ] . V_11 == V_13 ) ) {
F_4 ( & V_8 -> V_14 -> V_15 ,
L_5 ) ;
V_22 = - V_23 ;
} else {
V_22 = 0 ;
}
return V_22 ;
}
int F_10 ( struct V_1 * V_8 )
{
int V_7 = 0 ;
int V_24 , V_25 ;
T_1 V_22 = 0 ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_7 = F_7 ( V_8 -> V_16 , & V_22 , 1 ,
V_17 [ V_24 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 -> V_9 [ V_24 ] . V_20 = 0 ;
}
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_7 = F_7 ( V_8 -> V_16 , & V_22 , 1 ,
V_26 [ V_24 * 2 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_8 -> V_16 , & V_22 , 1 ,
V_26 [ ( V_24 * 2 ) + 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
V_8 -> V_9 [ V_24 ] . V_27 [ V_25 ] = V_28 ;
}
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
do {
V_7 = F_5 ( V_8 -> V_16 , & V_22 , 1 ,
V_29 [ V_24 ] ) ;
if ( V_7 < 0 )
return V_7 ;
} while ( V_22 != 0 );
}
return 0 ;
}
int T_2 F_11 ( struct V_1 * V_8 )
{
int V_7 = 0 ;
char * V_30 ;
V_30 = F_12 ( V_31 , V_32 ) ;
if ( V_30 == NULL ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_6 ) ;
return - V_33 ;
}
sprintf ( V_30 , L_7 , V_34 , F_13 ( & V_8 -> V_14 -> V_15 ) ) ;
V_8 -> V_4 . V_30 = V_30 ;
V_8 -> V_4 . V_35 = V_31 ;
V_8 -> V_4 . V_36 = - 1 ;
V_8 -> V_4 . V_37 = F_8 ;
V_8 -> V_4 . V_38 = F_9 ;
V_8 -> V_4 . V_39 = F_3 ;
V_8 -> V_4 . V_40 = F_6 ;
V_7 = F_14 ( & ( V_8 -> V_4 ) ) ;
if ( V_7 ) {
F_4 ( & V_8 -> V_14 -> V_15 , L_8 ) ;
F_15 ( V_8 -> V_4 . V_30 ) ;
}
return V_7 ;
}
void F_16 ( struct V_1 * V_8 )
{
const char * V_30 = V_8 -> V_4 . V_30 ;
if ( F_17 ( & ( V_8 -> V_4 ) ) )
F_4 ( & V_8 -> V_14 -> V_15 , L_9 ) ;
F_15 ( V_30 ) ;
}
