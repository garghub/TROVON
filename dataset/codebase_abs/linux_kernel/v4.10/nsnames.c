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
F_6 () ;
V_5 = F_7 ( V_2 , NULL , 0 , FALSE ) ;
return ( V_5 ) ;
}
T_2
F_8 ( T_3 V_6 , struct V_7 * V_8 )
{
T_2 V_9 ;
struct V_1 * V_2 ;
const char * V_10 ;
F_2 ( V_11 , V_6 ) ;
V_2 = F_9 ( V_6 ) ;
if ( ! V_2 ) {
F_10 ( V_12 ) ;
}
V_9 = F_11 ( V_8 , V_13 ) ;
if ( F_12 ( V_9 ) ) {
F_10 ( V_9 ) ;
}
V_10 = F_13 ( V_2 ) ;
F_14 ( V_8 -> V_14 , V_10 ) ;
( ( char * ) V_8 -> V_14 ) [ V_15 ] = 0 ;
F_15 ( ( V_16 , L_1 , ( char * ) V_8 -> V_14 ) ) ;
F_10 ( V_17 ) ;
}
T_2
F_16 ( T_3 V_6 ,
struct V_7 * V_8 , T_4 V_18 )
{
T_2 V_9 ;
struct V_1 * V_2 ;
T_1 V_19 ;
F_2 ( V_20 , V_6 ) ;
V_2 = F_9 ( V_6 ) ;
if ( ! V_2 ) {
F_10 ( V_12 ) ;
}
V_19 =
F_7 ( V_2 , NULL , 0 , V_18 ) ;
if ( ! V_19 ) {
F_10 ( V_12 ) ;
}
V_9 = F_11 ( V_8 , V_19 ) ;
if ( F_12 ( V_9 ) ) {
F_10 ( V_9 ) ;
}
( void ) F_7 ( V_2 , V_8 -> V_14 ,
V_19 , V_18 ) ;
if ( F_12 ( V_9 ) ) {
F_10 ( V_9 ) ;
}
F_15 ( ( V_16 , L_2 ,
( char * ) V_8 -> V_14 , ( V_21 ) V_19 ) ) ;
F_10 ( V_17 ) ;
}
V_21
F_7 ( struct V_1 * V_2 ,
char * V_22 , V_21 V_23 , T_4 V_18 )
{
V_21 V_24 = 0 , V_25 ;
char V_26 [ V_15 ] ;
T_4 V_27 ;
char V_28 , * V_29 , * V_30 ;
struct V_1 * V_31 ;
F_2 ( V_32 , V_2 ) ;
#define F_17 ( T_5 , V_5 , T_6 , V_24 ) \
do { \
if ((length) < (size)) \
{ \
(path)[(length)] = (byte); \
} \
(length)++; \
} while (0)
if ( ! V_22 ) {
V_23 = 0 ;
}
if ( ! V_2 ) {
goto V_33;
}
V_31 = V_2 ;
while ( V_31 && V_31 != V_34 ) {
if ( V_31 != V_2 ) {
F_17 ( V_22 , V_23 ,
V_35 , V_24 ) ;
}
F_18 ( V_26 , & V_31 -> V_26 ) ;
V_27 = V_18 ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
V_28 = V_26 [ 4 - V_25 - 1 ] ;
if ( V_27 && V_28 != '_' ) {
V_27 = FALSE ;
}
if ( ! V_27 ) {
F_17 ( V_22 , V_23 , V_28 , V_24 ) ;
}
}
V_31 = V_31 -> V_36 ;
}
F_17 ( V_22 , V_23 , V_37 , V_24 ) ;
if ( V_24 <= V_23 ) {
V_29 = V_22 ;
V_30 = V_22 + V_24 - 1 ;
while ( V_29 < V_30 ) {
V_28 = * V_29 ;
* V_29 ++ = * V_30 ;
* V_30 -- = V_28 ;
}
}
V_33:
F_17 ( V_22 , V_23 , '\0' , V_24 ) ;
#undef F_17
F_19 ( V_24 ) ;
}
char * F_3 ( struct V_1 * V_2 ,
T_4 V_18 )
{
char * V_3 ;
T_1 V_5 ;
F_2 ( V_38 , V_2 ) ;
V_5 = F_7 ( V_2 , NULL , 0 , V_18 ) ;
if ( ! V_5 ) {
F_4 ( NULL ) ;
}
V_3 = F_20 ( V_5 ) ;
if ( ! V_3 ) {
F_21 ( ( V_39 , L_3 , ( V_21 ) V_5 ) ) ;
F_4 ( NULL ) ;
}
( void ) F_7 ( V_2 , V_3 , V_5 ,
V_18 ) ;
F_4 ( V_3 ) ;
}
