static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ,
V_8 + V_9 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 >= 0 )
* V_3 = F_3 ( V_4 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_10 ,
enum V_11 clock )
{
T_1 V_3 ;
T_2 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 , & V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 &= 0x0000ffff ;
if ( V_10 > 0 ) {
V_3 &= 0x000000ff ;
if ( ( V_10 % 44100 ) == 0 ) {
V_3 |= 0x00000100 ;
if ( V_10 / 44100 == 2 )
V_3 |= 0x00008000 ;
} else if ( ( V_10 % 48000 ) == 0 ) {
V_3 |= 0x00000200 ;
if ( V_10 / 48000 == 2 )
V_3 |= 0x00008000 ;
} else {
return - V_12 ;
}
}
if ( clock != V_13 ) {
V_3 &= 0x0000ff00 ;
V_3 |= clock + 1 ;
}
V_4 = F_5 ( V_3 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_9 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 & 0x00008000 )
V_4 = F_5 ( 0x0000001a ) ;
else
V_4 = F_5 ( 0x0000000d ) ;
return F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_15 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
}
int F_6 ( struct V_1 * V_2 , unsigned int * V_10 )
{
T_1 V_3 = 0x0 ;
unsigned int V_16 = 0 ;
int V_5 ;
while ( V_3 == 0x0 || V_16 ++ < 5 ) {
V_5 = F_1 ( V_2 , & V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 = ( V_3 & 0xff000000 ) >> 24 ;
}
if ( ( V_3 & 0x0f ) == 0x01 )
* V_10 = 44100 ;
else if ( ( V_3 & 0x0f ) == 0x02 )
* V_10 = 48000 ;
else
return - V_12 ;
if ( ( V_3 & 0xf0 ) == 0x80 )
* V_10 *= 2 ;
else if ( ( V_3 & 0xf0 ) != 0x00 )
return - V_12 ;
return V_5 ;
}
int F_7 ( struct V_1 * V_2 , enum V_11 * clock )
{
T_1 V_3 ;
int V_5 ;
V_5 = F_1 ( V_2 , & V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
* clock = ( ( V_3 & 0x00ff0000 ) >> 16 ) - 1 ;
if ( * clock < 0 || * clock > V_17 )
return - V_18 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_2 V_4 ;
T_1 V_3 ;
unsigned int V_19 ;
int V_5 ;
V_3 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 -> V_21 ; ++ V_19 )
V_3 |= F_9 ( V_19 ) ;
if ( V_2 -> V_20 -> V_22 )
V_3 |= 0x0000ff00 ;
if ( V_2 -> V_20 -> V_23 )
V_3 |= 0x00030000 ;
V_4 = F_5 ( V_3 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_24 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 -> V_25 ; ++ V_19 )
V_3 |= F_9 ( V_19 ) ;
if ( V_2 -> V_20 -> V_22 )
V_3 |= 0x0000ff00 ;
if ( V_2 -> V_20 -> V_23 )
V_3 |= 0x00030000 ;
V_4 = F_5 ( V_3 ) ;
return F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_26 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_10 )
{
T_2 V_4 ;
int V_5 ;
V_4 = F_5 ( 0x00200000 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_27 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_4 ( V_2 , V_10 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_2 V_4 ;
V_4 = 0 ;
F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_28 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
V_4 = 0 ;
F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_29 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_4 = F_5 ( 0x00000001 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_28 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 = F_5 ( 0x00000001 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_29 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 = F_5 ( 0x00002000 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_27 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 = F_5 ( 0x00000001 ) ;
return F_2 ( V_2 -> V_6 ,
V_14 ,
V_8 + V_30 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_4 ;
V_4 = F_5 ( 0x00000000 ) ;
F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_31 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
V_4 = F_5 ( 0x00000000 ) ;
F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_32 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
V_4 = F_5 ( 0x00000000 ) ;
F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_33 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
F_14 ( & V_2 -> V_34 ) ;
F_14 ( & V_2 -> V_35 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_10 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_16 ( & V_2 -> V_36 , V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_17 ( & V_2 -> V_34 ,
F_18 ( & V_2 -> V_36 ) ,
F_19 ( V_2 -> V_6 ) -> V_37 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_16 ( & V_2 -> V_38 , V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_17 ( & V_2 -> V_35 ,
F_18 ( & V_2 -> V_38 ) ,
F_19 ( V_2 -> V_6 ) -> V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 = F_5 ( V_2 -> V_34 . V_39 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_31 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
goto error;
V_4 = F_5 ( 0x00000002 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_32 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
goto error;
V_4 = F_5 ( V_2 -> V_35 . V_39 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_14 ,
V_8 + V_33 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_5 < 0 )
goto error;
return 0 ;
error:
F_13 ( V_2 ) ;
return V_5 ;
}
int F_20 ( struct V_1 * V_2 )
{
unsigned int V_40 ;
int V_5 ;
V_5 = F_21 ( & V_2 -> V_35 , V_2 -> V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
V_40 = V_2 -> V_20 -> V_25 ;
if ( V_2 -> V_20 -> V_22 )
V_40 += 8 ;
if ( V_2 -> V_20 -> V_23 )
V_40 += 2 ;
V_5 = F_22 ( & V_2 -> V_38 , V_2 -> V_6 , V_41 ,
V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_21 ( & V_2 -> V_34 , V_2 -> V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
V_40 = V_2 -> V_20 -> V_21 ;
if ( V_2 -> V_20 -> V_22 )
V_40 += 8 ;
if ( V_2 -> V_20 -> V_23 )
V_40 += 2 ;
V_5 = F_22 ( & V_2 -> V_36 , V_2 -> V_6 , V_42 ,
V_40 ) ;
if ( V_5 < 0 )
F_23 ( & V_2 -> V_38 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_36 ) ;
F_26 ( & V_2 -> V_36 ) ;
F_25 ( & V_2 -> V_38 ) ;
F_26 ( & V_2 -> V_38 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_38 ) ;
F_23 ( & V_2 -> V_36 ) ;
F_28 ( & V_2 -> V_35 ) ;
F_28 ( & V_2 -> V_34 ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned int V_43 ;
int V_5 ;
if ( V_2 -> V_44 == 0 )
return 0 ;
V_5 = F_6 ( V_2 , & V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_43 != V_10 ||
F_30 ( & V_2 -> V_36 ) ||
F_30 ( & V_2 -> V_38 ) ) {
F_11 ( V_2 ) ;
F_26 ( & V_2 -> V_36 ) ;
F_26 ( & V_2 -> V_38 ) ;
F_13 ( V_2 ) ;
}
if ( ! F_31 ( & V_2 -> V_36 ) ) {
F_32 ( V_45 ,
& V_2 -> V_36 , & V_2 -> V_38 ) ;
V_5 = F_15 ( V_2 , V_10 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_10 ( V_2 , V_10 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_12 ( V_2 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_33 ( & V_2 -> V_36 ,
V_2 -> V_34 . V_39 ,
F_19 ( V_2 -> V_6 ) -> V_37 ) ;
if ( V_5 < 0 )
goto error;
if ( ! F_34 ( & V_2 -> V_36 ,
V_46 ) ) {
V_5 = - V_47 ;
goto error;
}
}
if ( ! F_31 ( & V_2 -> V_38 ) ) {
V_5 = F_33 ( & V_2 -> V_38 ,
V_2 -> V_35 . V_39 ,
F_19 ( V_2 -> V_6 ) -> V_37 ) ;
if ( V_5 < 0 )
goto error;
if ( ! F_34 ( & V_2 -> V_38 ,
V_46 ) ) {
V_5 = - V_47 ;
goto error;
}
}
return 0 ;
error:
F_26 ( & V_2 -> V_36 ) ;
F_26 ( & V_2 -> V_38 ) ;
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
return V_5 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 > 0 )
return;
F_26 ( & V_2 -> V_36 ) ;
F_26 ( & V_2 -> V_38 ) ;
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_48 = true ;
F_37 ( & V_2 -> V_49 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_5 ;
F_39 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_51 < 0 ) {
V_5 = - V_52 ;
goto V_53;
}
if ( V_2 -> V_51 ++ == 0 )
F_36 ( V_2 ) ;
V_5 = 0 ;
V_53:
F_40 ( & V_2 -> V_50 ) ;
return V_5 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_50 ) ;
if ( F_42 ( V_2 -> V_51 <= 0 ) )
goto V_53;
if ( -- V_2 -> V_51 == 0 )
F_36 ( V_2 ) ;
V_53:
F_40 ( & V_2 -> V_50 ) ;
}
