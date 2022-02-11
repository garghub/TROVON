static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_16 = F_5 ( V_6 -> V_15 ) ;
unsigned int V_17 ;
unsigned char V_18 ;
int V_19 ;
int V_20 ;
V_18 = V_21 | V_22 |
F_6 ( V_16 ) | F_7 ( V_14 ) ;
F_2 ( V_2 -> V_9 + V_10 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_23 ; V_20 ++ ) {
F_8 ( V_18 , V_2 -> V_9 + V_24 ) ;
V_19 = F_9 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_19 )
return V_19 ;
V_17 = F_10 ( V_2 -> V_9 + V_24 ) & V_4 -> V_25 ;
if ( F_11 ( V_4 , V_16 ) )
V_17 = F_12 ( V_4 , V_17 ) ;
V_13 [ V_20 ] = V_17 ;
}
return V_6 -> V_23 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_17 = V_4 -> V_26 [ V_14 ] ;
int V_20 ;
F_8 ( V_27 , V_2 -> V_9 + V_28 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_23 ; V_20 ++ ) {
V_17 = V_13 [ V_20 ] ;
F_14 ( V_17 , V_2 -> V_9 + F_15 ( V_14 ) ) ;
}
V_4 -> V_26 [ V_14 ] = V_17 ;
return V_6 -> V_23 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
switch ( V_13 [ 0 ] ) {
case V_29 :
V_13 [ 0 ] = 0 ;
V_13 [ 1 ] = ( V_14 == 1 ) ? V_30 : 0 ;
break;
default:
return - V_31 ;
}
return V_6 -> V_23 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const struct V_34 * V_35 = V_2 -> V_36 ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_18 ( V_2 , V_33 -> V_37 [ 0 ] , 32 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_38 = F_19 ( V_2 -> V_9 + V_39 ,
0 , V_40 , 0 ) ;
if ( ! V_2 -> V_38 )
return - V_41 ;
V_19 = F_20 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_42 [ 0 ] ;
if ( V_35 -> V_43 ) {
V_4 -> type = V_44 ;
V_4 -> V_45 = V_46 | V_47 | V_48 ;
V_4 -> V_49 = 8 ;
V_4 -> V_25 = 0x0fff ;
V_4 -> V_50 = & V_51 ;
V_4 -> V_52 = F_3 ;
} else {
V_4 -> type = V_53 ;
}
V_4 = & V_2 -> V_42 [ 1 ] ;
if ( V_35 -> V_54 ) {
V_4 -> type = V_55 ;
V_4 -> V_45 = V_56 | V_47 ;
V_4 -> V_49 = 4 ;
V_4 -> V_25 = 0x0fff ;
V_4 -> V_50 = & V_51 ;
V_4 -> V_57 = F_13 ;
V_19 = F_21 ( V_4 ) ;
if ( V_19 )
return V_19 ;
} else {
V_4 -> type = V_53 ;
}
V_4 = & V_2 -> V_42 [ 2 ] ;
V_19 = F_22 ( V_2 , V_4 , NULL , V_58 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_42 [ 3 ] ;
F_23 ( V_4 , V_2 -> V_38 ) ;
V_2 -> V_38 -> V_59 = F_16 ;
return 0 ;
}
