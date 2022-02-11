static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
V_3 [ 0 ] = 0x80 ;
V_4 = F_2 ( V_2 , V_3 + 1 , 2 ) ;
if ( V_4 >= 0 )
V_3 [ 3 ] = 0xc0 | V_4 ;
return V_4 ;
}
static void F_3 ( struct V_5 * V_6 , T_2 * V_3 ,
unsigned int V_7 )
{
struct V_1 * V_2 ;
unsigned int V_8 ;
unsigned int V_9 ;
T_1 * V_10 ;
V_2 = F_4 ( V_6 -> V_11 ) ;
if ( V_2 == NULL )
return;
V_7 /= 4 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
V_10 = ( T_1 * ) & V_3 [ V_8 ] ;
V_9 = V_10 [ 3 ] & 0xf ;
if ( V_9 > 0 )
F_5 ( V_6 -> V_11 , V_10 + 1 , V_9 ) ;
}
}
static void F_6 ( struct V_5 * V_6 ,
unsigned long long V_12 , T_2 * V_3 )
{
unsigned long V_13 ;
F_7 ( & V_6 -> V_14 , V_13 ) ;
V_6 -> V_15 = F_8 ( * V_3 ) ;
F_9 ( & V_6 -> V_14 , V_13 ) ;
F_10 ( & V_6 -> V_16 ) ;
}
static void F_11 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_21 , int V_22 , int V_23 ,
int V_24 , unsigned long long V_12 ,
void * V_25 , T_3 V_7 , void * V_26 )
{
struct V_5 * V_6 = V_26 ;
T_2 * V_3 = ( T_2 * ) V_25 ;
if ( V_12 == V_6 -> V_27 . V_12 )
F_6 ( V_6 , V_12 , V_3 ) ;
else if ( V_12 == V_6 -> V_27 . V_12 + 4 )
F_3 ( V_6 , V_3 , V_7 ) ;
F_12 ( V_18 , V_20 , V_28 ) ;
}
int F_13 ( struct V_5 * V_6 )
{
struct V_29 * V_30 = F_14 ( V_6 -> V_31 ) ;
T_2 V_25 [ 2 ] ;
int V_32 ;
V_25 [ 0 ] = F_15 ( ( V_30 -> V_18 -> V_33 << 16 ) |
( V_6 -> V_27 . V_12 >> 32 ) ) ;
V_25 [ 1 ] = F_15 ( V_6 -> V_27 . V_12 ) ;
V_32 = F_16 ( V_6 -> V_31 , V_34 ,
V_35 + V_36 ,
& V_25 , sizeof( V_25 ) , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_25 [ 0 ] = F_15 ( ( V_30 -> V_18 -> V_33 << 16 ) |
( V_6 -> V_27 . V_12 >> 32 ) ) ;
V_25 [ 1 ] = F_15 ( V_6 -> V_27 . V_12 + 4 ) ;
return F_16 ( V_6 -> V_31 , V_34 ,
V_35 + V_37 ,
& V_25 , sizeof( V_25 ) , 0 ) ;
}
int F_17 ( struct V_5 * V_6 )
{
static const struct V_38 V_39 = {
. V_40 = 0xffffe0000000ull ,
. V_41 = 0xffffe000ffffull ,
} ;
int V_32 ;
V_6 -> V_27 . V_7 = 12 ;
V_6 -> V_27 . V_42 = F_11 ;
V_6 -> V_27 . V_26 = V_6 ;
V_32 = F_18 ( & V_6 -> V_27 ,
& V_39 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_13 ( V_6 ) ;
if ( V_32 < 0 )
goto error;
V_32 = F_19 ( & V_6 -> V_43 , V_6 -> V_31 ,
V_35 + V_44 ,
4 , F_1 ) ;
if ( V_32 < 0 )
goto error;
return V_32 ;
error:
F_20 ( & V_6 -> V_27 ) ;
V_6 -> V_27 . V_42 = NULL ;
return V_32 ;
}
void F_21 ( struct V_5 * V_6 )
{
F_22 ( & V_6 -> V_43 ) ;
F_20 ( & V_6 -> V_27 ) ;
}
