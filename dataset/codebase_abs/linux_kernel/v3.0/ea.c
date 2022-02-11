void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , unsigned V_5 )
{
unsigned V_6 = 0 ;
while ( V_6 < V_5 ) {
char V_7 [ 4 + 255 + 1 + 8 ] ;
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
if ( V_6 + 4 > V_5 ) {
F_2 ( V_2 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_5 ) ;
return;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 , 4 , V_7 ) ) return;
if ( V_9 -> V_10 ) {
if ( F_4 ( V_9 ) != 8 ) {
F_2 ( V_2 , L_4 ,
V_4 ? L_2 : L_3 , V_3 , V_6 ) ;
return;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_11 + 9 , V_7 + 4 ) )
return;
F_5 ( V_2 , F_6 ( V_9 ) , V_9 -> V_12 , F_7 ( V_9 ) ) ;
}
V_6 += V_9 -> V_11 + F_4 ( V_9 ) + 5 ;
}
if ( ! V_4 ) F_8 ( V_2 , V_3 , ( V_5 + 511 ) >> 9 ) ;
else {
struct V_13 * V_14 ;
struct V_12 * V_12 ;
if ( ( V_12 = F_9 ( V_2 , V_3 , & V_14 ) ) ) {
F_10 ( V_2 , & V_12 -> V_15 ) ;
F_11 ( V_14 ) ;
F_8 ( V_2 , V_3 , 1 ) ;
}
}
}
static char * F_12 ( struct V_1 * V_2 , int V_4 , T_1 V_3 , int V_16 )
{
char * V_17 ;
if ( ! ( V_17 = F_13 ( V_16 + 1 , V_18 ) ) ) {
F_14 ( L_5 ) ;
return NULL ;
}
if ( F_3 ( V_2 , V_3 , V_4 , 0 , V_16 , V_17 ) ) {
F_15 ( V_17 ) ;
return NULL ;
}
V_17 [ V_16 ] = 0 ;
return V_17 ;
}
static void F_16 ( struct V_1 * V_2 , int V_4 , T_1 V_3 ,
const char * V_19 , int V_16 )
{
F_17 ( V_2 , V_3 , V_4 , 0 , V_16 , V_19 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_20 * V_20 , char * V_21 ,
char * V_22 , int V_16 )
{
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
char V_7 [ 4 + 255 + 1 + 8 ] ;
struct V_8 * V_9 ;
struct V_8 * V_23 = F_19 ( V_20 ) ;
for ( V_9 = F_20 ( V_20 ) ; V_9 < V_23 ; V_9 = F_21 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 )
goto V_10;
if ( F_4 ( V_9 ) >= V_16 )
return - V_25 ;
memcpy ( V_22 , F_22 ( V_9 ) , F_4 ( V_9 ) ) ;
V_22 [ F_4 ( V_9 ) ] = 0 ;
return 0 ;
}
V_3 = F_23 ( V_20 -> V_26 ) ;
V_5 = F_23 ( V_20 -> V_27 ) ;
V_4 = V_20 -> V_28 ;
V_6 = 0 ;
while ( V_6 < V_5 ) {
V_9 = (struct V_8 * ) V_7 ;
if ( V_6 + 4 > V_5 ) {
F_2 ( V_2 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_5 ) ;
return - V_29 ;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 , 4 , V_7 ) ) return - V_29 ;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_11 + 1 + ( V_9 -> V_10 ? 8 : 0 ) , V_7 + 4 ) )
return - V_29 ;
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 )
goto V_10;
if ( F_4 ( V_9 ) >= V_16 )
return - V_25 ;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_11 + 1 , F_4 ( V_9 ) , V_22 ) )
return - V_29 ;
V_22 [ F_4 ( V_9 ) ] = 0 ;
return 0 ;
}
V_6 += V_9 -> V_11 + F_4 ( V_9 ) + 5 ;
}
return - V_30 ;
V_10:
if ( F_7 ( V_9 ) >= V_16 )
return - V_25 ;
if ( F_3 ( V_2 , F_6 ( V_9 ) , V_9 -> V_12 , 0 , F_7 ( V_9 ) , V_22 ) )
return - V_29 ;
V_22 [ F_7 ( V_9 ) ] = 0 ;
return 0 ;
}
char * F_24 ( struct V_1 * V_2 , struct V_20 * V_20 , char * V_21 , int * V_16 )
{
char * V_17 ;
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_8 * V_23 = F_19 ( V_20 ) ;
for ( V_9 = F_20 ( V_20 ) ; V_9 < V_23 ; V_9 = F_21 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 )
return F_12 ( V_2 , V_9 -> V_12 , F_6 ( V_9 ) , * V_16 = F_7 ( V_9 ) ) ;
if ( ! ( V_17 = F_13 ( ( * V_16 = F_4 ( V_9 ) ) + 1 , V_18 ) ) ) {
F_14 ( L_5 ) ;
return NULL ;
}
memcpy ( V_17 , F_22 ( V_9 ) , F_4 ( V_9 ) ) ;
V_17 [ F_4 ( V_9 ) ] = 0 ;
return V_17 ;
}
V_3 = F_23 ( V_20 -> V_26 ) ;
V_5 = F_23 ( V_20 -> V_27 ) ;
V_4 = V_20 -> V_28 ;
V_6 = 0 ;
while ( V_6 < V_5 ) {
char V_7 [ 4 + 255 + 1 + 8 ] ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_6 + 4 > V_5 ) {
F_2 ( V_2 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_5 ) ;
return NULL ;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 , 4 , V_7 ) ) return NULL ;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_11 + 1 + ( V_9 -> V_10 ? 8 : 0 ) , V_7 + 4 ) )
return NULL ;
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 )
return F_12 ( V_2 , V_9 -> V_12 , F_6 ( V_9 ) , * V_16 = F_7 ( V_9 ) ) ;
if ( ! ( V_17 = F_13 ( ( * V_16 = F_4 ( V_9 ) ) + 1 , V_18 ) ) ) {
F_14 ( L_5 ) ;
return NULL ;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_11 + 1 , F_4 ( V_9 ) , V_17 ) ) {
F_15 ( V_17 ) ;
return NULL ;
}
V_17 [ F_4 ( V_9 ) ] = 0 ;
return V_17 ;
}
V_6 += V_9 -> V_11 + F_4 ( V_9 ) + 5 ;
}
return NULL ;
}
void F_25 ( struct V_31 * V_31 , struct V_20 * V_20 , const char * V_21 ,
const char * V_19 , int V_16 )
{
T_2 V_32 = V_31 -> V_33 ;
struct V_1 * V_2 = V_31 -> V_34 ;
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
unsigned char V_35 [ 4 ] ;
struct V_8 * V_9 ;
struct V_8 * V_23 = F_19 ( V_20 ) ;
for ( V_9 = F_20 ( V_20 ) ; V_9 < V_23 ; V_9 = F_21 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 ) {
if ( F_7 ( V_9 ) == V_16 )
F_16 ( V_2 , V_9 -> V_12 , F_6 ( V_9 ) , V_19 , V_16 ) ;
} else if ( F_4 ( V_9 ) == V_16 ) {
memcpy ( F_22 ( V_9 ) , V_19 , V_16 ) ;
}
return;
}
V_3 = F_23 ( V_20 -> V_26 ) ;
V_5 = F_23 ( V_20 -> V_27 ) ;
V_4 = V_20 -> V_28 ;
V_6 = 0 ;
while ( V_6 < V_5 ) {
char V_7 [ 4 + 255 + 1 + 8 ] ;
V_9 = (struct V_8 * ) V_7 ;
if ( V_6 + 4 > V_5 ) {
F_2 ( V_2 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_5 ) ;
return;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 , 4 , V_7 ) ) return;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_11 + 1 + ( V_9 -> V_10 ? 8 : 0 ) , V_7 + 4 ) )
return;
if ( ! strcmp ( V_9 -> V_24 , V_21 ) ) {
if ( V_9 -> V_10 ) {
if ( F_7 ( V_9 ) == V_16 )
F_16 ( V_2 , V_9 -> V_12 , F_6 ( V_9 ) , V_19 , V_16 ) ;
}
else {
if ( F_4 ( V_9 ) == V_16 )
F_17 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_11 + 1 , V_16 , V_19 ) ;
}
return;
}
V_6 += V_9 -> V_11 + F_4 ( V_9 ) + 5 ;
}
if ( ! F_26 ( V_20 -> V_36 ) ) {
V_20 -> V_36 = F_27 ( 0xc4 ) ;
}
if ( F_26 ( V_20 -> V_36 ) < 0xc4 || F_26 ( V_20 -> V_36 ) + F_26 ( V_20 -> V_37 ) + F_26 ( V_20 -> V_38 ) > 0x200 ) {
F_2 ( V_2 , L_6 ,
( unsigned long ) V_31 -> V_33 ,
F_23 ( V_20 -> V_36 ) , F_26 ( V_20 -> V_38 ) ) ;
return;
}
if ( ( F_26 ( V_20 -> V_38 ) || ! F_23 ( V_20 -> V_27 ) ) &&
F_26 ( V_20 -> V_36 ) + F_26 ( V_20 -> V_37 ) + F_26 ( V_20 -> V_38 ) + strlen ( V_21 ) + V_16 + 5 <= 0x200 ) {
V_9 = F_19 ( V_20 ) ;
* ( char * ) V_9 = 0 ;
V_9 -> V_11 = strlen ( V_21 ) ;
V_9 -> V_39 = V_16 ;
V_9 -> V_40 = V_16 >> 8 ;
strcpy ( V_9 -> V_24 , V_21 ) ;
memcpy ( F_22 ( V_9 ) , V_19 , V_16 ) ;
V_20 -> V_38 = F_27 ( F_26 ( V_20 -> V_38 ) + strlen ( V_21 ) + V_16 + 5 ) ;
goto V_17;
}
if ( F_26 ( V_20 -> V_38 ) && ! F_23 ( V_20 -> V_27 ) ) {
T_1 V_41 ;
struct V_13 * V_14 ;
char * V_19 ;
if ( ! ( V_41 = F_28 ( V_2 , V_32 , 1 , 0 ) ) ) return;
if ( ! ( V_19 = F_29 ( V_2 , V_41 , & V_14 ) ) ) {
F_8 ( V_2 , V_41 , 1 ) ;
return;
}
memcpy ( V_19 , F_20 ( V_20 ) , F_26 ( V_20 -> V_38 ) ) ;
V_20 -> V_27 = F_30 ( F_26 ( V_20 -> V_38 ) ) ;
V_20 -> V_38 = F_27 ( 0 ) ;
V_20 -> V_26 = F_30 ( V_41 ) ;
V_20 -> V_28 = F_30 ( 0 ) ;
F_31 ( V_14 ) ;
F_11 ( V_14 ) ;
}
V_6 = F_23 ( V_20 -> V_27 ) + 5 + strlen ( V_21 ) + V_16 ;
V_5 = ( F_23 ( V_20 -> V_27 ) + 511 ) >> 9 ;
if ( V_6 >= 30000 ) goto V_42;
while ( ( ( V_6 + 511 ) >> 9 ) > V_5 ) {
if ( ! V_5 ) {
T_1 V_43 = F_28 ( V_2 , V_32 , 1 , 0 ) ;
if ( ! V_43 ) goto V_42;
V_20 -> V_26 = F_30 ( V_43 ) ;
V_20 -> V_28 = 0 ;
V_5 ++ ;
} else if ( ! V_20 -> V_28 ) {
if ( F_32 ( V_2 , F_23 ( V_20 -> V_26 ) + V_5 ) ) {
V_5 ++ ;
} else {
T_1 V_44 ;
int V_45 ;
if ( ! ( V_44 = F_28 ( V_2 , V_32 , 1 , 1 - ( ( V_6 + 511 ) >> 9 ) ) ) )
goto V_42;
for ( V_45 = 0 ; V_45 < V_5 ; V_45 ++ ) {
struct V_13 * V_46 , * V_47 ;
void * V_48 , * V_49 ;
if ( ! ( V_48 = F_33 ( V_2 , F_23 ( V_20 -> V_26 ) + V_45 , & V_46 , V_5 - V_45 - 1 ) ) ) {
F_8 ( V_2 , V_44 , ( V_6 + 511 ) >> 9 ) ;
goto V_42;
}
if ( ! ( V_49 = F_29 ( V_2 , V_44 + V_45 , & V_47 ) ) ) {
F_11 ( V_46 ) ;
F_8 ( V_2 , V_44 , ( V_6 + 511 ) >> 9 ) ;
goto V_42;
}
memcpy ( V_49 , V_48 , 512 ) ;
F_11 ( V_46 ) ;
F_31 ( V_47 ) ;
F_11 ( V_47 ) ;
}
F_8 ( V_2 , F_23 ( V_20 -> V_26 ) , V_5 ) ;
V_20 -> V_26 = F_30 ( V_44 ) ;
V_5 = ( V_6 + 511 ) >> 9 ;
}
}
if ( V_20 -> V_28 ) {
if ( F_34 ( V_2 , F_23 ( V_20 -> V_26 ) ,
0 , V_5 ) != - 1 ) {
V_5 ++ ;
} else {
goto V_42;
}
}
}
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = strlen ( V_21 ) ;
V_35 [ 2 ] = V_16 & 0xff ;
V_35 [ 3 ] = V_16 >> 8 ;
if ( F_17 ( V_2 , F_23 ( V_20 -> V_26 ) , V_20 -> V_28 , F_23 ( V_20 -> V_27 ) , 4 , V_35 ) ) goto V_42;
if ( F_17 ( V_2 , F_23 ( V_20 -> V_26 ) , V_20 -> V_28 , F_23 ( V_20 -> V_27 ) + 4 , V_35 [ 1 ] + 1 , V_21 ) ) goto V_42;
if ( F_17 ( V_2 , F_23 ( V_20 -> V_26 ) , V_20 -> V_28 , F_23 ( V_20 -> V_27 ) + 5 + V_35 [ 1 ] , V_16 , V_19 ) ) goto V_42;
V_20 -> V_27 = F_30 ( V_6 ) ;
V_17:
F_35 ( V_31 ) -> V_50 += 5 + strlen ( V_21 ) + V_16 ;
return;
V_42:
if ( F_23 ( V_20 -> V_26 ) )
if ( V_20 -> V_28 ) F_36 ( V_2 , F_23 ( V_20 -> V_26 ) , 1 , ( F_23 ( V_20 -> V_27 ) + 511 ) >> 9 ) ;
else F_8 ( V_2 , F_23 ( V_20 -> V_26 ) + ( ( F_23 ( V_20 -> V_27 ) + 511 ) >> 9 ) , V_5 - ( ( F_23 ( V_20 -> V_27 ) + 511 ) >> 9 ) ) ;
else V_20 -> V_26 = V_20 -> V_27 = F_30 ( 0 ) ;
}
