static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_10 . V_8 ;
struct V_11 * V_12 = V_8 -> V_12 ;
int V_13 ;
F_2 ( V_8 , 0x10a180 , 0x01000000 | ( V_6 ? 0x10000000 : 0 ) | V_3 ) ;
for ( V_13 = 0 ; V_13 < V_5 ; V_13 += 4 ) {
if ( ( V_13 & 0xff ) == 0 )
F_2 ( V_8 , 0x10a188 , ( V_3 + V_13 ) >> 8 ) ;
F_2 ( V_8 , 0x10a184 , F_3 ( V_12 , V_4 + V_13 ) ) ;
}
while ( V_13 & 0xff ) {
F_2 ( V_8 , 0x10a184 , 0x00000000 ) ;
V_13 += 4 ;
}
}
static void
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_10 . V_8 ;
struct V_11 * V_12 = V_8 -> V_12 ;
int V_13 ;
F_2 ( V_8 , 0x10a1c0 , 0x01000000 | V_3 ) ;
for ( V_13 = 0 ; V_13 < V_5 ; V_13 += 4 )
F_2 ( V_8 , 0x10a1c4 , F_3 ( V_12 , V_4 + V_13 ) ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_10 . V_8 ;
F_2 ( V_8 , 0x10a1c0 , V_14 ) ;
F_2 ( V_8 , 0x10a1c0 , F_6 ( V_8 , 0x10a1c4 ) + V_15 ) ;
return F_6 ( V_8 , 0x10a1c4 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 . V_10 . V_8 ;
F_2 ( V_8 , 0x10a104 , V_16 ) ;
F_2 ( V_8 , 0x10a10c , 0x00000000 ) ;
F_2 ( V_8 , 0x10a100 , 0x00000002 ) ;
}
static int
F_8 ( struct V_1 * V_2 , T_2 type , bool V_17 ,
T_1 * V_18 , T_1 * V_19 )
{
struct V_20 * V_10 = & V_2 -> V_9 . V_10 ;
struct V_11 * V_12 = V_10 -> V_8 -> V_12 ;
struct V_21 V_3 ;
if ( ! F_9 ( V_12 , type , & V_3 ) ) {
F_10 ( V_10 , L_1 , type ) ;
return - V_22 ;
}
if ( ! V_17 )
return 0 ;
F_1 ( V_2 , V_3 . V_23 , V_3 . V_24 , V_3 . V_25 , false ) ;
F_1 ( V_2 , V_3 . V_26 , V_3 . V_27 , V_3 . V_28 , true ) ;
F_4 ( V_2 , V_3 . V_29 , V_3 . V_30 , V_3 . V_31 ) ;
if ( V_18 ) {
* V_18 = V_3 . V_18 ;
* V_19 = V_3 . V_19 ;
return 0 ;
}
return F_7 ( V_2 , V_3 . V_18 ) , 0 ;
}
static int
F_11 ( struct V_32 * V_9 , bool V_17 )
{
struct V_1 * V_2 = V_1 ( V_9 ) ;
struct V_20 * V_10 = & V_2 -> V_9 . V_10 ;
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_33 V_34 ;
T_1 V_35 , args ;
int V_36 ;
if ( V_33 ( V_12 , 'I' , & V_34 ) || V_34 . V_37 != 1 ||
V_34 . V_38 < 0x1c ) {
F_10 ( V_10 , L_2 ) ;
return - V_22 ;
}
if ( V_17 ) {
F_12 ( V_8 , 0x000200 , 0x00002000 , 0x00000000 ) ;
F_12 ( V_8 , 0x000200 , 0x00002000 , 0x00002000 ) ;
F_6 ( V_8 , 0x000200 ) ;
while ( F_6 ( V_8 , 0x10a10c ) & 0x00000006 ) {
}
}
V_36 = F_8 ( V_2 , 0x04 , V_17 , & V_35 , & args ) ;
if ( V_36 )
return V_36 ;
if ( V_17 ) {
T_1 V_3 = F_5 ( V_2 , args + 0x08 , 0x08 ) ;
T_1 V_4 = F_13 ( V_12 , V_34 . V_39 + 0x14 ) ;
T_1 V_5 = F_13 ( V_12 , V_34 . V_39 + 0x16 ) ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
if ( V_17 ) {
T_1 V_3 = F_5 ( V_2 , args + 0x08 , 0x10 ) ;
T_1 V_4 = F_13 ( V_12 , V_34 . V_39 + 0x18 ) ;
T_1 V_5 = F_13 ( V_12 , V_34 . V_39 + 0x1a ) ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
if ( V_17 ) {
F_2 ( V_8 , 0x10a040 , 0x00005000 ) ;
F_7 ( V_2 , V_35 ) ;
while ( ! ( F_6 ( V_8 , 0x10a040 ) & 0x00002000 ) ) {
}
}
return F_8 ( V_2 , 0x01 , V_17 , NULL , NULL ) ;
}
int
F_14 ( struct V_7 * V_8 , int V_40 ,
struct V_32 * * V_41 )
{
return F_15 ( & V_42 , V_8 , V_40 , V_41 ) ;
}
