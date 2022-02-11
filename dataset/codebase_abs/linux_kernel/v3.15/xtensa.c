T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
return F_2 ( V_5 , V_5 -> V_3 + V_3 ) ;
}
void
F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_4 ( V_5 , V_5 -> V_3 + V_3 , V_6 ) ;
}
int
F_5 ( struct V_1 * V_7 ,
struct V_1 * V_8 ,
struct V_9 * V_10 , void * V_6 , T_1 V_11 ,
struct V_1 * * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_15 = F_6 ( V_7 , V_8 , V_10 , NULL ,
0x10000 , 0x1000 ,
V_16 , & V_14 ) ;
* V_12 = F_7 ( V_14 ) ;
return V_15 ;
}
void
F_8 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = ( void * ) V_18 ;
T_1 V_19 = F_9 ( V_5 , 0xd04 ) ;
T_1 V_20 = F_9 ( V_5 , 0xc20 ) ;
T_1 V_21 = F_9 ( V_5 , 0xc28 ) ;
T_1 V_22 = F_9 ( V_5 , 0xd0c ) ;
if ( V_20 & 0x10 )
F_10 ( V_5 , L_1 ) ;
F_11 ( V_5 , 0xc20 , V_20 ) ;
V_20 = F_9 ( V_5 , 0xc20 ) ;
if ( V_19 == 0x10001 && V_22 == 0x200 && V_21 && ! V_20 ) {
F_12 ( V_5 , L_2 ) ;
F_13 ( V_5 , V_5 -> V_3 + 0xd94 , 0 , V_5 -> V_23 ) ;
}
}
int
F_14 ( struct V_1 * V_7 ,
struct V_1 * V_8 ,
struct V_9 * V_10 , T_1 V_3 , bool V_24 ,
const char * V_25 , const char * V_26 ,
int V_27 , void * * V_12 )
{
struct V_4 * V_5 ;
int V_15 ;
V_15 = F_15 ( V_7 , V_8 , V_10 , V_24 , V_25 ,
V_26 , V_27 , V_12 ) ;
V_5 = * V_12 ;
if ( V_15 )
return V_15 ;
F_16 ( V_5 ) -> V_20 = F_8 ;
V_5 -> V_3 = V_3 ;
return 0 ;
}
int
F_17 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_18 ( V_2 ) ;
struct V_4 * V_5 = ( void * ) V_2 ;
const struct V_30 * V_31 ;
char V_32 [ 32 ] ;
int V_33 , V_15 ;
T_1 V_34 ;
V_15 = F_19 ( & V_5 -> V_35 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_5 -> V_36 ) {
snprintf ( V_32 , sizeof( V_32 ) , L_3 ,
V_5 -> V_3 >> 12 ) ;
V_15 = F_20 ( & V_31 , V_32 , F_21 ( V_29 ) ) ;
if ( V_15 ) {
F_10 ( V_5 , L_4 , V_32 ) ;
return V_15 ;
}
if ( V_31 -> V_11 > 0x40000 ) {
F_10 ( V_5 , L_5 , V_32 ) ;
F_22 ( V_31 ) ;
return - V_37 ;
}
V_15 = F_23 ( V_2 , NULL , 0x40000 , 0x1000 , 0 ,
& V_5 -> V_36 ) ;
if ( V_15 ) {
F_22 ( V_31 ) ;
return V_15 ;
}
F_12 ( V_5 , L_6 ,
V_5 -> V_36 -> V_3 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_11 / 4 ; V_33 ++ )
F_11 ( V_5 -> V_36 , V_33 * 4 , * ( ( T_1 * ) V_31 -> V_6 + V_33 ) ) ;
F_22 ( V_31 ) ;
}
F_11 ( V_5 , 0xd10 , 0x1fffffff ) ;
F_11 ( V_5 , 0xd08 , 0x0fffffff ) ;
F_11 ( V_5 , 0xd28 , V_5 -> V_38 ) ;
F_11 ( V_5 , 0xc20 , 0x3f ) ;
F_11 ( V_5 , 0xd84 , 0x3f ) ;
F_11 ( V_5 , 0xcc0 , V_5 -> V_36 -> V_3 >> 8 ) ;
F_11 ( V_5 , 0xcc4 , 0x1c ) ;
F_11 ( V_5 , 0xcc8 , V_5 -> V_36 -> V_11 >> 8 ) ;
V_34 = F_2 ( V_5 , 0x0 ) ;
F_11 ( V_5 , 0xde0 , V_34 ) ;
F_11 ( V_5 , 0xce8 , 0xf ) ;
F_11 ( V_5 , 0xc20 , 0x3f ) ;
F_11 ( V_5 , 0xd84 , 0x3f ) ;
return 0 ;
}
int
F_24 ( struct V_1 * V_2 , bool V_39 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_11 ( V_5 , 0xd84 , 0 ) ;
F_11 ( V_5 , 0xd94 , 0 ) ;
if ( ! V_39 )
F_25 ( NULL , & V_5 -> V_36 ) ;
return F_26 ( & V_5 -> V_35 , V_39 ) ;
}
