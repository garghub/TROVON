static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_8 = V_5 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_7 -> V_10 -> V_11 -> V_12 ) ;
V_9 ++ ) {
if ( V_7 -> V_13 -> V_14 [ V_9 ] == V_15 )
continue;
V_8 +=
sprintf ( V_8 , L_1 , V_9 ,
V_7 -> V_13 -> V_14 [ V_9 ] ) ;
}
return ( V_8 - V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 ,
( V_7 -> V_16 ) ? F_5 ( V_7 -> V_16 ) : L_3 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_8 = V_5 ;
int V_9 ;
if ( V_7 -> V_17 & V_18 ) {
for ( V_9 = 0 ; V_9 < F_7 ( V_7 -> V_19 ) ; V_9 ++ ) {
if ( V_7 -> V_13 -> V_20 [ V_9 ] )
V_8 += sprintf ( V_8 , L_2 ,
F_5 ( V_7 -> V_13 -> V_20 [ V_9 ] ) ) ;
else
V_8 += sprintf ( V_8 , L_4 ) ;
}
}
return V_8 - V_5 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_5 ,
V_7 -> V_21 , V_7 -> V_22 , V_7 -> V_23 , V_7 -> V_24 ) ;
}
static T_1
F_9 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_5 , T_2 V_31 , T_3 V_32 )
{
struct V_6 * V_2 = F_2 ( F_10 ( V_28 ) ) ;
unsigned int V_33 = 0x100 ;
T_2 V_34 = V_31 ;
T_4 * V_35 = ( T_4 * ) V_5 ;
if ( F_11 ( V_36 ) )
V_33 = V_37 ;
if ( V_31 >= V_33 )
return 0 ;
if ( V_31 + V_32 > V_33 ) {
V_33 -= V_31 ;
V_32 = V_33 ;
} else {
V_33 = V_32 ;
}
if ( ( V_31 & 1 ) && V_33 ) {
T_4 V_38 ;
F_12 ( V_2 , V_31 , & V_38 ) ;
V_35 [ V_31 - V_34 ] = V_38 ;
V_31 ++ ;
V_33 -- ;
}
if ( ( V_31 & 3 ) && V_33 > 2 ) {
T_5 V_38 ;
F_13 ( V_2 , V_31 , & V_38 ) ;
V_35 [ V_31 - V_34 ] = ( V_38 >> 8 ) & 0xff ;
V_35 [ V_31 - V_34 + 1 ] = V_38 & 0xff ;
V_31 += 2 ;
V_33 -= 2 ;
}
while ( V_33 > 3 ) {
T_6 V_38 ;
F_14 ( V_2 , V_31 , & V_38 ) ;
V_35 [ V_31 - V_34 ] = ( V_38 >> 24 ) & 0xff ;
V_35 [ V_31 - V_34 + 1 ] = ( V_38 >> 16 ) & 0xff ;
V_35 [ V_31 - V_34 + 2 ] = ( V_38 >> 8 ) & 0xff ;
V_35 [ V_31 - V_34 + 3 ] = V_38 & 0xff ;
V_31 += 4 ;
V_33 -= 4 ;
}
if ( V_33 >= 2 ) {
T_5 V_38 ;
F_13 ( V_2 , V_31 , & V_38 ) ;
V_35 [ V_31 - V_34 ] = ( V_38 >> 8 ) & 0xff ;
V_35 [ V_31 - V_34 + 1 ] = V_38 & 0xff ;
V_31 += 2 ;
V_33 -= 2 ;
}
if ( V_33 > 0 ) {
T_4 V_38 ;
F_12 ( V_2 , V_31 , & V_38 ) ;
V_35 [ V_31 - V_34 ] = V_38 ;
V_31 ++ ;
-- V_33 ;
}
return V_32 ;
}
static T_1
F_15 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_5 , T_2 V_31 , T_3 V_32 )
{
struct V_6 * V_2 = F_2 ( F_10 ( V_28 ) ) ;
unsigned int V_33 = V_32 ;
T_2 V_34 = V_31 ;
T_4 * V_35 = ( T_4 * ) V_5 ;
if ( V_31 >= V_37 )
return 0 ;
if ( V_31 + V_32 > V_37 ) {
V_33 = V_37 - V_31 ;
V_32 = V_33 ;
}
if ( ( V_31 & 1 ) && V_33 ) {
F_16 ( V_2 , V_31 , V_35 [ V_31 - V_34 ] ) ;
V_31 ++ ;
V_33 -- ;
}
if ( ( V_31 & 3 ) && ( V_33 > 2 ) ) {
T_5 V_38 = V_35 [ V_31 - V_34 + 1 ] ;
V_38 |= ( T_5 ) V_35 [ V_31 - V_34 ] << 8 ;
F_17 ( V_2 , V_31 , V_38 ) ;
V_31 += 2 ;
V_33 -= 2 ;
}
while ( V_33 > 3 ) {
T_6 V_38 = V_35 [ V_31 - V_34 + 3 ] ;
V_38 |= ( T_6 ) V_35 [ V_31 - V_34 + 2 ] << 8 ;
V_38 |= ( T_6 ) V_35 [ V_31 - V_34 + 1 ] << 16 ;
V_38 |= ( T_6 ) V_35 [ V_31 - V_34 ] << 24 ;
F_18 ( V_2 , V_31 , V_38 ) ;
V_31 += 4 ;
V_33 -= 4 ;
}
if ( V_33 >= 2 ) {
T_5 V_38 = V_35 [ V_31 - V_34 + 1 ] ;
V_38 |= ( T_5 ) V_35 [ V_31 - V_34 ] << 8 ;
F_17 ( V_2 , V_31 , V_38 ) ;
V_31 += 2 ;
V_33 -= 2 ;
}
if ( V_33 ) {
F_16 ( V_2 , V_31 , V_35 [ V_31 - V_34 ] ) ;
V_31 ++ ;
-- V_33 ;
}
return V_32 ;
}
int F_19 ( struct V_6 * V_7 )
{
int V_39 = 0 ;
V_39 = F_20 ( & V_7 -> V_2 , & V_40 ) ;
if ( ! V_39 && ( V_7 -> V_17 & V_18 ) ) {
V_39 |= F_21 ( & V_7 -> V_2 , & V_41 ) ;
V_39 |= F_21 ( & V_7 -> V_2 , & V_42 ) ;
V_39 |= F_21 ( & V_7 -> V_2 , & V_43 ) ;
}
if ( V_39 )
F_22 ( L_6 ,
F_5 ( V_7 ) ) ;
return V_39 ;
}
void F_23 ( struct V_6 * V_7 )
{
F_24 ( & V_7 -> V_2 , & V_40 ) ;
if ( V_7 -> V_17 & V_18 ) {
F_25 ( & V_7 -> V_2 , & V_41 ) ;
F_25 ( & V_7 -> V_2 , & V_42 ) ;
F_25 ( & V_7 -> V_2 , & V_43 ) ;
}
}
static T_1 F_26 ( struct V_44 * V_45 , const char * V_5 ,
T_3 V_32 )
{
long V_38 ;
int V_46 ;
if ( F_27 ( V_5 , 0 , & V_38 ) < 0 )
return - V_47 ;
if ( V_38 == V_48 ) {
V_46 = F_28 () ;
goto exit;
}
if ( V_38 < 0 || V_38 >= V_49 )
return - V_47 ;
V_46 = F_29 ( ( int ) V_38 ) ;
exit:
if ( ! V_46 )
V_46 = V_32 ;
return V_46 ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_50 * V_51 = F_31 ( V_2 ) ;
if ( V_51 )
return sprintf ( V_5 , L_7 , V_51 -> V_52 ) ;
else
return - V_53 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_50 * V_51 = F_31 ( V_2 ) ;
if ( V_51 )
return sprintf ( V_5 , L_8 , V_51 -> V_12 ) ;
else
return - V_53 ;
}
