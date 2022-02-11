static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
static int V_5 ;
if ( V_5 == 0 ) {
V_3 = F_2 ( V_2 -> V_6 . V_7 , 30 , 0 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_6 . V_7 , 30 , 0 ) ;
F_4 ( 2 ) ;
V_3 = F_2 ( V_2 -> V_6 . V_7 , 29 , 31 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_6 . V_7 , 29 , 22 , 0x420 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_3 = F_2 ( V_2 -> V_6 . V_7 , V_4 ,
V_8 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
}
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ )
V_3 = F_3 ( V_2 -> V_6 . V_7 , V_4 , V_8 ) ;
F_4 ( 2 ) ;
V_5 = 1 ;
}
if ( V_2 -> V_6 . V_10 != 4 ) {
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = 1 ;
F_5 ( V_2 -> V_18 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_7 ( V_2 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 |= V_9 ;
V_19 = F_8 ( V_2 , V_8 , V_19 ) ;
if ( V_19 < 0 )
return V_19 ;
do {
V_19 = F_7 ( V_2 , V_8 ) ;
if ( V_19 < 0 )
return V_19 ;
} while ( V_19 & V_9 );
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_7 ( V_2 , V_21 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 |= V_22 ;
V_20 = F_8 ( V_2 , V_21 , V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( F_10 ( V_2 ) ) {
V_20 = F_7 ( V_2 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 &= ~ ( V_24 | V_25 ) ;
if ( V_2 -> V_26 == V_27 )
V_20 |= ( V_24 | V_25 ) ;
else if ( V_2 -> V_26 == V_28 )
V_20 |= V_24 ;
else if ( V_2 -> V_26 == V_29 )
V_20 |= V_25 ;
V_20 = F_8 ( V_2 , V_23 , V_20 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_8 ( V_2 , V_30 , V_31 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_7 ( V_2 , V_23 ) ;
V_20 |= V_32 ;
return F_8 ( V_2 , V_23 , V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_10 == 4 )
F_13 ( V_2 ) ;
else
V_2 -> V_33 = V_34 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_10 == 4 )
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 = F_7 ( V_2 , V_30 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
