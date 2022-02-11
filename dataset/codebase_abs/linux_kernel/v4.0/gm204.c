static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , bool V_6 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
int V_9 ;
F_2 ( V_2 , 0x10a180 , 0x01000000 | ( V_6 ? 0x10000000 : 0 ) | V_3 ) ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 += 4 ) {
if ( ( V_9 & 0xff ) == 0 )
F_2 ( V_2 , 0x10a188 , ( V_3 + V_9 ) >> 8 ) ;
F_2 ( V_2 , 0x10a184 , F_3 ( V_8 , V_4 + V_9 ) ) ;
}
while ( V_9 & 0xff ) {
F_2 ( V_2 , 0x10a184 , 0x00000000 ) ;
V_9 += 4 ;
}
}
static void
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
int V_9 ;
F_2 ( V_2 , 0x10a1c0 , 0x01000000 | V_3 ) ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 += 4 )
F_2 ( V_2 , 0x10a1c4 , F_3 ( V_8 , V_4 + V_9 ) ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
F_2 ( V_2 , 0x10a1c0 , V_10 ) ;
F_2 ( V_2 , 0x10a1c0 , F_6 ( V_2 , 0x10a1c4 ) + V_11 ) ;
return F_6 ( V_2 , 0x10a1c4 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
F_2 ( V_2 , 0x10a104 , V_12 ) ;
F_2 ( V_2 , 0x10a10c , 0x00000000 ) ;
F_2 ( V_2 , 0x10a100 , 0x00000002 ) ;
}
static int
F_8 ( struct V_1 * V_2 , T_2 type , bool V_13 ,
T_1 * V_14 , T_1 * V_15 )
{
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_16 V_3 ;
if ( ! F_9 ( V_8 , type , & V_3 ) ) {
F_10 ( V_2 , L_1 , type ) ;
return - V_17 ;
}
if ( ! V_13 )
return 0 ;
F_1 ( V_2 , V_3 . V_18 , V_3 . V_19 , V_3 . V_20 , false ) ;
F_1 ( V_2 , V_3 . V_21 , V_3 . V_22 , V_3 . V_23 , true ) ;
F_4 ( V_2 , V_3 . V_24 , V_3 . V_25 , V_3 . V_26 ) ;
if ( V_14 ) {
* V_14 = V_3 . V_14 ;
* V_15 = V_3 . V_15 ;
return 0 ;
}
return F_7 ( V_2 , V_3 . V_14 ) , 0 ;
}
static int
F_11 ( struct V_27 * V_28 , bool V_13 )
{
struct V_1 * V_2 = ( void * ) F_12 ( V_28 ) ;
struct V_7 * V_8 = V_7 ( V_2 ) ;
struct V_29 V_30 ;
T_1 V_31 , args ;
int V_32 ;
if ( V_29 ( V_8 , 'I' , & V_30 ) || V_30 . V_33 != 1 ||
V_30 . V_34 < 0x1c ) {
F_10 ( V_2 , L_2 ) ;
return - V_17 ;
}
if ( V_13 ) {
F_13 ( V_2 , 0x000200 , 0x00002000 , 0x00000000 ) ;
F_13 ( V_2 , 0x000200 , 0x00002000 , 0x00002000 ) ;
F_6 ( V_2 , 0x000200 ) ;
while ( F_6 ( V_2 , 0x10a10c ) & 0x00000006 ) {
}
}
V_32 = F_8 ( V_2 , 0x04 , V_13 , & V_31 , & args ) ;
if ( V_32 )
return V_32 ;
if ( V_13 ) {
T_1 V_3 = F_5 ( V_2 , args + 0x08 , 0x08 ) ;
T_1 V_4 = F_14 ( V_8 , V_30 . V_35 + 0x14 ) ;
T_1 V_5 = F_14 ( V_8 , V_30 . V_35 + 0x16 ) ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
if ( V_13 ) {
T_1 V_3 = F_5 ( V_2 , args + 0x08 , 0x10 ) ;
T_1 V_4 = F_14 ( V_8 , V_30 . V_35 + 0x18 ) ;
T_1 V_5 = F_14 ( V_8 , V_30 . V_35 + 0x1a ) ;
F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
if ( V_13 ) {
F_2 ( V_2 , 0x10a040 , 0x00005000 ) ;
F_7 ( V_2 , V_31 ) ;
while ( ! ( F_6 ( V_2 , 0x10a040 ) & 0x00002000 ) ) {
}
}
return F_8 ( V_2 , 0x01 , V_13 , NULL , NULL ) ;
}
