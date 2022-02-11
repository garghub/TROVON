static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned int V_4 , V_5 , V_6 ;
V_6 = F_2 ( V_3 -> V_7 + V_8 ) ;
while ( V_6 & V_9 ) {
if ( V_6 & V_10 )
F_3 ( V_10 , V_3 -> V_7 + V_8 ) ;
V_5 = ( V_6 & V_10 ? V_11 : 0 ) |
( V_6 & V_12 ? 0 : V_13 ) ;
V_4 = F_2 ( V_3 -> V_7 + V_14 ) & 0xff ;
if ( F_4 ( V_4 ) & 1 )
V_5 ^= V_13 ;
F_5 ( V_3 -> V_15 , V_4 , V_5 ) ;
V_6 = F_2 ( V_3 -> V_7 + V_8 ) ;
}
return V_16 ;
}
static T_1 F_6 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
unsigned int V_6 ;
F_7 ( & V_3 -> V_17 ) ;
V_6 = F_2 ( V_3 -> V_7 + V_8 ) ;
if ( V_3 -> V_18 == V_3 -> V_19 ) {
F_8 ( V_1 ) ;
} else if ( V_6 & V_20 ) {
F_3 ( V_3 -> V_21 [ V_3 -> V_19 ] , V_3 -> V_7 + V_14 ) ;
V_3 -> V_19 = ( V_3 -> V_19 + 1 ) & ( sizeof( V_3 -> V_21 ) - 1 ) ;
}
F_9 ( & V_3 -> V_17 ) ;
return V_16 ;
}
static int F_10 ( struct V_22 * V_15 , unsigned char V_23 )
{
struct V_3 * V_3 = V_15 -> V_24 ;
unsigned long V_25 ;
unsigned int V_18 ;
F_11 ( & V_3 -> V_17 , V_25 ) ;
if ( F_2 ( V_3 -> V_7 + V_8 ) & V_20 ) {
F_3 ( V_23 , V_3 -> V_7 + V_14 ) ;
} else {
if ( V_3 -> V_18 == V_3 -> V_19 )
F_12 ( V_3 -> V_26 -> V_1 [ 1 ] ) ;
V_18 = ( V_3 -> V_18 + 1 ) & ( sizeof( V_3 -> V_21 ) - 1 ) ;
if ( V_18 != V_3 -> V_19 ) {
V_3 -> V_21 [ V_3 -> V_18 ] = V_23 ;
V_3 -> V_18 = V_18 ;
}
}
F_13 ( & V_3 -> V_17 , V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_15 )
{
struct V_3 * V_3 = V_15 -> V_24 ;
int V_27 ;
V_27 = F_15 ( V_3 -> V_26 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_16 ( V_3 -> V_26 -> V_1 [ 0 ] , F_1 , 0 ,
F_17 ( V_3 -> V_26 ) , V_3 ) ;
if ( V_27 ) {
F_18 ( V_28 L_1 ,
V_3 -> V_26 -> V_1 [ 0 ] , V_27 ) ;
F_19 ( V_3 -> V_26 ) ;
return V_27 ;
}
V_27 = F_16 ( V_3 -> V_26 -> V_1 [ 1 ] , F_6 , 0 ,
F_17 ( V_3 -> V_26 ) , V_3 ) ;
if ( V_27 ) {
F_18 ( V_28 L_1 ,
V_3 -> V_26 -> V_1 [ 1 ] , V_27 ) ;
F_20 ( V_3 -> V_26 -> V_1 [ 0 ] , V_3 ) ;
F_19 ( V_3 -> V_26 ) ;
return V_27 ;
}
V_3 -> V_29 = 1 ;
F_21 ( V_3 -> V_26 -> V_1 [ 0 ] ) ;
F_3 ( V_30 , V_3 -> V_7 + V_31 ) ;
return 0 ;
}
static void F_22 ( struct V_22 * V_15 )
{
struct V_3 * V_3 = V_15 -> V_24 ;
F_3 ( 0 , V_3 -> V_7 + V_31 ) ;
F_23 ( V_3 -> V_26 -> V_1 [ 0 ] ) ;
V_3 -> V_29 = 0 ;
F_20 ( V_3 -> V_26 -> V_1 [ 1 ] , V_3 ) ;
F_20 ( V_3 -> V_26 -> V_1 [ 0 ] , V_3 ) ;
F_19 ( V_3 -> V_26 ) ;
}
static void F_24 ( struct V_3 * V_3 )
{
int V_32 = 100 ;
while ( V_32 -- ) {
if ( ( F_2 ( V_3 -> V_7 + V_14 ) & 0xff ) == 0xff )
break;
}
}
static unsigned int F_25 ( struct V_3 * V_3 ,
unsigned int V_33 )
{
unsigned int V_23 ;
F_3 ( V_30 | V_33 , V_3 -> V_7 + V_31 ) ;
F_26 ( 2 ) ;
V_23 = F_2 ( V_3 -> V_7 + V_8 ) ;
return V_23 & ( V_34 | V_35 ) ;
}
static int F_27 ( struct V_3 * V_3 )
{
unsigned int V_36 ;
int V_27 = 0 ;
V_36 = F_25 ( V_3 , V_37 ) ;
if ( V_36 != V_35 ) {
F_18 ( L_2 , V_36 ) ;
V_27 = - V_38 ;
}
V_36 = F_25 ( V_3 , 0 ) ;
if ( V_36 != ( V_34 | V_35 ) ) {
F_18 ( L_3 , V_36 ) ;
V_27 = - V_38 ;
}
V_36 = F_25 ( V_3 , V_39 ) ;
if ( V_36 != V_34 ) {
F_18 ( L_4 , V_36 ) ;
V_27 = - V_38 ;
}
F_3 ( 0 , V_3 -> V_7 + V_31 ) ;
return V_27 ;
}
static int F_28 ( struct V_40 * V_26 )
{
struct V_3 * V_3 ;
struct V_22 * V_22 ;
int V_27 ;
V_3 = F_29 ( sizeof( struct V_3 ) , V_41 ) ;
V_22 = F_29 ( sizeof( struct V_22 ) , V_41 ) ;
if ( ! V_3 || ! V_22 ) {
V_27 = - V_42 ;
goto free;
}
V_22 -> V_43 . type = V_44 ;
V_22 -> V_45 = F_10 ;
V_22 -> V_29 = F_14 ;
V_22 -> V_46 = F_22 ;
F_30 ( V_22 -> V_47 , F_31 ( & V_26 -> V_26 ) , sizeof( V_22 -> V_47 ) ) ;
F_30 ( V_22 -> V_48 , F_31 ( & V_26 -> V_26 ) , sizeof( V_22 -> V_48 ) ) ;
V_22 -> V_24 = V_3 ;
V_22 -> V_26 . V_49 = & V_26 -> V_26 ;
V_3 -> V_15 = V_22 ;
V_3 -> V_26 = V_26 ;
F_32 ( V_26 , V_3 ) ;
F_33 ( & V_3 -> V_17 ) ;
if ( ! F_34 ( V_26 -> V_50 . V_51 ,
V_26 -> V_50 . V_52 - V_26 -> V_50 . V_51 + 1 ,
F_17 ( V_26 ) ) ) {
V_27 = - V_53 ;
goto free;
}
V_3 -> V_7 = V_26 -> V_54 ;
F_15 ( V_3 -> V_26 ) ;
F_3 ( 0 , V_3 -> V_7 + V_55 ) ;
F_3 ( 127 , V_3 -> V_7 + V_56 ) ;
F_24 ( V_3 ) ;
V_27 = F_27 ( V_3 ) ;
if ( V_27 )
goto V_57;
F_24 ( V_3 ) ;
F_19 ( V_3 -> V_26 ) ;
F_35 ( V_3 -> V_15 ) ;
return 0 ;
V_57:
F_19 ( V_3 -> V_26 ) ;
F_36 ( V_26 -> V_50 . V_51 , F_37 ( & V_26 -> V_50 ) ) ;
free:
F_32 ( V_26 , NULL ) ;
F_38 ( V_3 ) ;
F_38 ( V_22 ) ;
return V_27 ;
}
static int F_39 ( struct V_40 * V_26 )
{
struct V_3 * V_3 = F_40 ( V_26 ) ;
F_41 ( V_3 -> V_15 ) ;
F_36 ( V_26 -> V_50 . V_51 , F_37 ( & V_26 -> V_50 ) ) ;
F_32 ( V_26 , NULL ) ;
F_38 ( V_3 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_58 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_58 ) ;
}
