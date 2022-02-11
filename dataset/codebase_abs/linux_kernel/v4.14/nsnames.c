char * F_1 ( struct V_1 * V_2 )
{
char * V_3 ;
F_2 ( V_4 , V_2 ) ;
V_3 = F_3 ( V_2 , FALSE ) ;
F_4 ( V_3 ) ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
if ( F_6 ( V_2 ) != V_6 ) {
F_7 ( ( V_7 ,
L_1 ,
V_2 , F_6 ( V_2 ) ) ) ;
return ( 0 ) ;
}
V_5 = F_8 ( V_2 , NULL , 0 , FALSE ) ;
return ( V_5 ) ;
}
T_2
F_9 ( T_3 V_8 , struct V_9 * V_10 )
{
T_2 V_11 ;
struct V_1 * V_2 ;
const char * V_12 ;
F_2 ( V_13 , V_8 ) ;
V_2 = F_10 ( V_8 ) ;
if ( ! V_2 ) {
F_11 ( V_14 ) ;
}
V_11 = F_12 ( V_10 , V_15 ) ;
if ( F_13 ( V_11 ) ) {
F_11 ( V_11 ) ;
}
V_12 = F_14 ( V_2 ) ;
F_15 ( V_10 -> V_16 , V_12 ) ;
( ( char * ) V_10 -> V_16 ) [ V_17 ] = 0 ;
F_16 ( ( V_18 , L_2 , ( char * ) V_10 -> V_16 ) ) ;
F_11 ( V_19 ) ;
}
T_2
F_17 ( T_3 V_8 ,
struct V_9 * V_10 , T_4 V_20 )
{
T_2 V_11 ;
struct V_1 * V_2 ;
T_1 V_21 ;
F_2 ( V_22 , V_8 ) ;
V_2 = F_10 ( V_8 ) ;
if ( ! V_2 ) {
F_11 ( V_14 ) ;
}
V_21 =
F_8 ( V_2 , NULL , 0 , V_20 ) ;
if ( ! V_21 ) {
F_11 ( V_14 ) ;
}
V_11 = F_12 ( V_10 , V_21 ) ;
if ( F_13 ( V_11 ) ) {
F_11 ( V_11 ) ;
}
( void ) F_8 ( V_2 , V_10 -> V_16 ,
V_21 , V_20 ) ;
F_16 ( ( V_18 , L_3 ,
( char * ) V_10 -> V_16 , ( V_23 ) V_21 ) ) ;
F_11 ( V_19 ) ;
}
V_23
F_8 ( struct V_1 * V_2 ,
char * V_24 , V_23 V_25 , T_4 V_20 )
{
V_23 V_26 = 0 , V_27 ;
char V_28 [ V_17 ] ;
T_4 V_29 ;
char V_30 , * V_31 , * V_32 ;
struct V_1 * V_33 ;
F_2 ( V_34 , V_2 ) ;
#define F_18 ( T_5 , V_5 , T_6 , V_26 ) \
do { \
if ((length) < (size)) \
{ \
(path)[(length)] = (byte); \
} \
(length)++; \
} while (0)
if ( ! V_24 ) {
V_25 = 0 ;
}
if ( ! V_2 ) {
goto V_35;
}
V_33 = V_2 ;
while ( V_33 && V_33 != V_36 ) {
if ( V_33 != V_2 ) {
F_18 ( V_24 , V_25 ,
V_37 , V_26 ) ;
}
F_19 ( V_28 , & V_33 -> V_28 ) ;
V_29 = V_20 ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
V_30 = V_28 [ 4 - V_27 - 1 ] ;
if ( V_29 && V_30 != '_' ) {
V_29 = FALSE ;
}
if ( ! V_29 ) {
F_18 ( V_24 , V_25 , V_30 , V_26 ) ;
}
}
V_33 = V_33 -> V_38 ;
}
F_18 ( V_24 , V_25 , V_39 , V_26 ) ;
if ( V_26 <= V_25 ) {
V_31 = V_24 ;
V_32 = V_24 + V_26 - 1 ;
while ( V_31 < V_32 ) {
V_30 = * V_31 ;
* V_31 ++ = * V_32 ;
* V_32 -- = V_30 ;
}
}
V_35:
F_18 ( V_24 , V_25 , '\0' , V_26 ) ;
#undef F_18
F_20 ( V_26 ) ;
}
char * F_3 ( struct V_1 * V_2 ,
T_4 V_20 )
{
char * V_3 ;
T_1 V_5 ;
F_2 ( V_40 , V_2 ) ;
V_5 = F_8 ( V_2 , NULL , 0 , V_20 ) ;
if ( ! V_5 ) {
F_4 ( NULL ) ;
}
V_3 = F_21 ( V_5 ) ;
if ( ! V_3 ) {
F_7 ( ( V_7 , L_4 , ( V_23 ) V_5 ) ) ;
F_4 ( NULL ) ;
}
( void ) F_8 ( V_2 , V_3 , V_5 ,
V_20 ) ;
F_4 ( V_3 ) ;
}
