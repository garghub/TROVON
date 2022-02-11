static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 [] = { V_4 , V_5 , V_6 } ;
return F_2 ( V_7 . V_8 , V_3 , sizeof( V_3 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned char V_3 [] = { V_4 , V_9 } ;
F_2 ( V_7 . V_8 , V_3 , sizeof( V_3 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_10 )
{
unsigned char V_3 [] = { V_4 , V_11 , V_12 , 1 } ;
V_3 [ 2 ] = V_10 & 0xff ;
F_5 ( & V_2 -> V_13 , L_1 , V_10 ) ;
return F_2 ( V_7 . V_8 , V_3 , sizeof( V_3 ) ) ;
}
static int F_6 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
int V_18 ;
unsigned char * V_19 = V_17 ;
switch ( V_16 ) {
case V_20 :
for ( V_18 = 0 ; V_18 < V_19 [ 1 ] ; V_18 ++ )
F_7 ( V_7 . V_2 , V_19 [ 2 + V_18 ] , 0 ) ;
F_8 ( L_2 , & V_19 [ 2 ] , V_19 [ 1 ] ) ;
return V_21 ;
case V_4 :
if ( V_19 [ 2 ] == 1 ) {
for ( V_18 = 0 ; V_18 < ( V_19 [ 1 ] - 2 ) ; V_18 ++ )
F_7 ( V_7 . V_2 , V_19 [ V_18 + 4 ] , 0 ) ;
F_8 ( L_3 , & V_19 [ 4 ] , V_19 [ 1 ] - 2 ) ;
}
else if ( V_19 [ 1 ] != 2 )
F_8 ( L_4 , V_19 , V_19 [ 1 ] + 2 ) ;
return V_21 ;
}
return V_22 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_8 = F_10 ( V_24 -> V_13 . V_26 ) ;
struct V_1 * V_2 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_29 . type = V_30 ;
V_2 -> V_31 = F_4 ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_3 ;
F_12 ( V_2 -> V_34 , L_5 , sizeof( V_2 -> V_34 ) ) ;
F_12 ( V_2 -> V_35 , L_6 , sizeof( V_2 -> V_35 ) ) ;
V_7 . V_2 = V_2 ;
V_7 . V_36 . V_37 = F_6 ;
V_7 . V_8 = V_8 ;
F_13 ( V_8 , & V_7 . V_36 , 0 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_8 = F_10 ( V_24 -> V_13 . V_26 ) ;
F_4 ( V_7 . V_2 , V_38 ) ;
F_3 ( V_7 . V_2 ) ;
F_16 ( V_8 , & V_7 . V_36 ) ;
F_17 ( V_7 . V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_39 * V_13 )
{
F_4 ( V_7 . V_2 , V_38 ) ;
F_3 ( V_7 . V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_13 )
{
F_1 ( V_7 . V_2 ) ;
F_4 ( V_7 . V_2 , V_12 ) ;
return 0 ;
}
