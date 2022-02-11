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
if ( F_4 ( V_9 ) ) {
if ( F_5 ( V_9 ) != 8 ) {
F_2 ( V_2 , L_4 ,
V_4 ? L_2 : L_3 , V_3 , V_6 ) ;
return;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_10 + 9 , V_7 + 4 ) )
return;
F_6 ( V_2 , F_7 ( V_9 ) , F_8 ( V_9 ) , F_9 ( V_9 ) ) ;
}
V_6 += V_9 -> V_10 + F_5 ( V_9 ) + 5 ;
}
if ( ! V_4 ) F_10 ( V_2 , V_3 , ( V_5 + 511 ) >> 9 ) ;
else {
struct V_11 * V_12 ;
struct V_13 * V_13 ;
if ( ( V_13 = F_11 ( V_2 , V_3 , & V_12 ) ) ) {
F_12 ( V_2 , & V_13 -> V_14 ) ;
F_13 ( V_12 ) ;
F_10 ( V_2 , V_3 , 1 ) ;
}
}
}
static char * F_14 ( struct V_1 * V_2 , int V_4 , T_1 V_3 , int V_15 )
{
char * V_16 ;
if ( ! ( V_16 = F_15 ( V_15 + 1 , V_17 ) ) ) {
F_16 ( L_5 ) ;
return NULL ;
}
if ( F_3 ( V_2 , V_3 , V_4 , 0 , V_15 , V_16 ) ) {
F_17 ( V_16 ) ;
return NULL ;
}
V_16 [ V_15 ] = 0 ;
return V_16 ;
}
static void F_18 ( struct V_1 * V_2 , int V_4 , T_1 V_3 ,
const char * V_18 , int V_15 )
{
F_19 ( V_2 , V_3 , V_4 , 0 , V_15 , V_18 ) ;
}
int F_20 ( struct V_1 * V_2 , struct V_19 * V_19 , char * V_20 ,
char * V_21 , int V_15 )
{
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
char V_7 [ 4 + 255 + 1 + 8 ] ;
struct V_8 * V_9 ;
struct V_8 * V_22 = F_21 ( V_19 ) ;
for ( V_9 = F_22 ( V_19 ) ; V_9 < V_22 ; V_9 = F_23 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) )
goto V_24;
if ( F_5 ( V_9 ) >= V_15 )
return - V_25 ;
memcpy ( V_21 , F_24 ( V_9 ) , F_5 ( V_9 ) ) ;
V_21 [ F_5 ( V_9 ) ] = 0 ;
return 0 ;
}
V_3 = F_25 ( V_19 -> V_26 ) ;
V_5 = F_25 ( V_19 -> V_27 ) ;
V_4 = F_26 ( V_19 ) ;
V_6 = 0 ;
while ( V_6 < V_5 ) {
V_9 = (struct V_8 * ) V_7 ;
if ( V_6 + 4 > V_5 ) {
F_2 ( V_2 , L_1 ,
V_4 ? L_2 : L_3 , V_3 , V_5 ) ;
return - V_28 ;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 , 4 , V_7 ) ) return - V_28 ;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_10 + 1 + ( F_4 ( V_9 ) ? 8 : 0 ) , V_7 + 4 ) )
return - V_28 ;
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) )
goto V_24;
if ( F_5 ( V_9 ) >= V_15 )
return - V_25 ;
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_10 + 1 , F_5 ( V_9 ) , V_21 ) )
return - V_28 ;
V_21 [ F_5 ( V_9 ) ] = 0 ;
return 0 ;
}
V_6 += V_9 -> V_10 + F_5 ( V_9 ) + 5 ;
}
return - V_29 ;
V_24:
if ( F_9 ( V_9 ) >= V_15 )
return - V_25 ;
if ( F_3 ( V_2 , F_7 ( V_9 ) , F_8 ( V_9 ) , 0 , F_9 ( V_9 ) , V_21 ) )
return - V_28 ;
V_21 [ F_9 ( V_9 ) ] = 0 ;
return 0 ;
}
char * F_27 ( struct V_1 * V_2 , struct V_19 * V_19 , char * V_20 , int * V_15 )
{
char * V_16 ;
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
struct V_8 * V_9 ;
struct V_8 * V_22 = F_21 ( V_19 ) ;
for ( V_9 = F_22 ( V_19 ) ; V_9 < V_22 ; V_9 = F_23 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) )
return F_14 ( V_2 , F_8 ( V_9 ) , F_7 ( V_9 ) , * V_15 = F_9 ( V_9 ) ) ;
if ( ! ( V_16 = F_15 ( ( * V_15 = F_5 ( V_9 ) ) + 1 , V_17 ) ) ) {
F_16 ( L_5 ) ;
return NULL ;
}
memcpy ( V_16 , F_24 ( V_9 ) , F_5 ( V_9 ) ) ;
V_16 [ F_5 ( V_9 ) ] = 0 ;
return V_16 ;
}
V_3 = F_25 ( V_19 -> V_26 ) ;
V_5 = F_25 ( V_19 -> V_27 ) ;
V_4 = F_26 ( V_19 ) ;
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
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_10 + 1 + ( F_4 ( V_9 ) ? 8 : 0 ) , V_7 + 4 ) )
return NULL ;
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) )
return F_14 ( V_2 , F_8 ( V_9 ) , F_7 ( V_9 ) , * V_15 = F_9 ( V_9 ) ) ;
if ( ! ( V_16 = F_15 ( ( * V_15 = F_5 ( V_9 ) ) + 1 , V_17 ) ) ) {
F_16 ( L_5 ) ;
return NULL ;
}
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_10 + 1 , F_5 ( V_9 ) , V_16 ) ) {
F_17 ( V_16 ) ;
return NULL ;
}
V_16 [ F_5 ( V_9 ) ] = 0 ;
return V_16 ;
}
V_6 += V_9 -> V_10 + F_5 ( V_9 ) + 5 ;
}
return NULL ;
}
void F_28 ( struct V_30 * V_30 , struct V_19 * V_19 , const char * V_20 ,
const char * V_18 , int V_15 )
{
T_2 V_31 = V_30 -> V_32 ;
struct V_1 * V_2 = V_30 -> V_33 ;
unsigned V_6 ;
int V_4 , V_5 ;
T_1 V_3 ;
unsigned char V_34 [ 4 ] ;
struct V_8 * V_9 ;
struct V_8 * V_22 = F_21 ( V_19 ) ;
for ( V_9 = F_22 ( V_19 ) ; V_9 < V_22 ; V_9 = F_23 ( V_9 ) )
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) ) {
if ( F_9 ( V_9 ) == V_15 )
F_18 ( V_2 , F_8 ( V_9 ) , F_7 ( V_9 ) , V_18 , V_15 ) ;
} else if ( F_5 ( V_9 ) == V_15 ) {
memcpy ( F_24 ( V_9 ) , V_18 , V_15 ) ;
}
return;
}
V_3 = F_25 ( V_19 -> V_26 ) ;
V_5 = F_25 ( V_19 -> V_27 ) ;
V_4 = F_26 ( V_19 ) ;
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
if ( F_3 ( V_2 , V_3 , V_4 , V_6 + 4 , V_9 -> V_10 + 1 + ( F_4 ( V_9 ) ? 8 : 0 ) , V_7 + 4 ) )
return;
if ( ! strcmp ( V_9 -> V_23 , V_20 ) ) {
if ( F_4 ( V_9 ) ) {
if ( F_9 ( V_9 ) == V_15 )
F_18 ( V_2 , F_8 ( V_9 ) , F_7 ( V_9 ) , V_18 , V_15 ) ;
}
else {
if ( F_5 ( V_9 ) == V_15 )
F_19 ( V_2 , V_3 , V_4 , V_6 + 4 + V_9 -> V_10 + 1 , V_15 , V_18 ) ;
}
return;
}
V_6 += V_9 -> V_10 + F_5 ( V_9 ) + 5 ;
}
if ( ! F_29 ( V_19 -> V_35 ) ) {
V_19 -> V_35 = F_30 ( 0xc4 ) ;
}
if ( F_29 ( V_19 -> V_35 ) < 0xc4 || F_29 ( V_19 -> V_35 ) + F_29 ( V_19 -> V_36 ) + F_29 ( V_19 -> V_37 ) > 0x200 ) {
F_2 ( V_2 , L_6 ,
( unsigned long ) V_30 -> V_32 ,
F_29 ( V_19 -> V_35 ) , F_29 ( V_19 -> V_37 ) ) ;
return;
}
if ( ( F_29 ( V_19 -> V_37 ) || ! F_25 ( V_19 -> V_27 ) ) &&
F_29 ( V_19 -> V_35 ) + F_29 ( V_19 -> V_36 ) + F_29 ( V_19 -> V_37 ) + strlen ( V_20 ) + V_15 + 5 <= 0x200 ) {
V_9 = F_21 ( V_19 ) ;
* ( char * ) V_9 = 0 ;
V_9 -> V_10 = strlen ( V_20 ) ;
V_9 -> V_38 = V_15 ;
V_9 -> V_39 = V_15 >> 8 ;
strcpy ( V_9 -> V_23 , V_20 ) ;
memcpy ( F_24 ( V_9 ) , V_18 , V_15 ) ;
V_19 -> V_37 = F_30 ( F_29 ( V_19 -> V_37 ) + strlen ( V_20 ) + V_15 + 5 ) ;
goto V_16;
}
if ( F_29 ( V_19 -> V_37 ) && ! F_25 ( V_19 -> V_27 ) ) {
T_1 V_40 ;
struct V_11 * V_12 ;
char * V_18 ;
if ( ! ( V_40 = F_31 ( V_2 , V_31 , 1 , 0 ) ) ) return;
if ( ! ( V_18 = F_32 ( V_2 , V_40 , & V_12 ) ) ) {
F_10 ( V_2 , V_40 , 1 ) ;
return;
}
memcpy ( V_18 , F_22 ( V_19 ) , F_29 ( V_19 -> V_37 ) ) ;
V_19 -> V_27 = F_33 ( F_29 ( V_19 -> V_37 ) ) ;
V_19 -> V_37 = F_30 ( 0 ) ;
V_19 -> V_26 = F_33 ( V_40 ) ;
V_19 -> V_41 &= ~ V_42 ;
F_34 ( V_12 ) ;
F_13 ( V_12 ) ;
}
V_6 = F_25 ( V_19 -> V_27 ) + 5 + strlen ( V_20 ) + V_15 ;
V_5 = ( F_25 ( V_19 -> V_27 ) + 511 ) >> 9 ;
if ( V_6 >= 30000 ) goto V_43;
while ( ( ( V_6 + 511 ) >> 9 ) > V_5 ) {
if ( ! V_5 ) {
T_1 V_44 = F_31 ( V_2 , V_31 , 1 , 0 ) ;
if ( ! V_44 ) goto V_43;
V_19 -> V_26 = F_33 ( V_44 ) ;
V_19 -> V_41 &= ~ V_42 ;
V_5 ++ ;
} else if ( ! F_26 ( V_19 ) ) {
if ( F_35 ( V_2 , F_25 ( V_19 -> V_26 ) + V_5 ) ) {
V_5 ++ ;
} else {
T_1 V_45 ;
int V_46 ;
if ( ! ( V_45 = F_31 ( V_2 , V_31 , 1 , 1 - ( ( V_6 + 511 ) >> 9 ) ) ) )
goto V_43;
for ( V_46 = 0 ; V_46 < V_5 ; V_46 ++ ) {
struct V_11 * V_47 , * V_48 ;
void * V_49 , * V_50 ;
if ( ! ( V_49 = F_36 ( V_2 , F_25 ( V_19 -> V_26 ) + V_46 , & V_47 , V_5 - V_46 - 1 ) ) ) {
F_10 ( V_2 , V_45 , ( V_6 + 511 ) >> 9 ) ;
goto V_43;
}
if ( ! ( V_50 = F_32 ( V_2 , V_45 + V_46 , & V_48 ) ) ) {
F_13 ( V_47 ) ;
F_10 ( V_2 , V_45 , ( V_6 + 511 ) >> 9 ) ;
goto V_43;
}
memcpy ( V_50 , V_49 , 512 ) ;
F_13 ( V_47 ) ;
F_34 ( V_48 ) ;
F_13 ( V_48 ) ;
}
F_10 ( V_2 , F_25 ( V_19 -> V_26 ) , V_5 ) ;
V_19 -> V_26 = F_33 ( V_45 ) ;
V_5 = ( V_6 + 511 ) >> 9 ;
}
}
if ( F_26 ( V_19 ) ) {
if ( F_37 ( V_2 , F_25 ( V_19 -> V_26 ) ,
0 , V_5 ) != - 1 ) {
V_5 ++ ;
} else {
goto V_43;
}
}
}
V_34 [ 0 ] = 0 ;
V_34 [ 1 ] = strlen ( V_20 ) ;
V_34 [ 2 ] = V_15 & 0xff ;
V_34 [ 3 ] = V_15 >> 8 ;
if ( F_19 ( V_2 , F_25 ( V_19 -> V_26 ) , F_26 ( V_19 ) , F_25 ( V_19 -> V_27 ) , 4 , V_34 ) ) goto V_43;
if ( F_19 ( V_2 , F_25 ( V_19 -> V_26 ) , F_26 ( V_19 ) , F_25 ( V_19 -> V_27 ) + 4 , V_34 [ 1 ] + 1 , V_20 ) ) goto V_43;
if ( F_19 ( V_2 , F_25 ( V_19 -> V_26 ) , F_26 ( V_19 ) , F_25 ( V_19 -> V_27 ) + 5 + V_34 [ 1 ] , V_15 , V_18 ) ) goto V_43;
V_19 -> V_27 = F_33 ( V_6 ) ;
V_16:
F_38 ( V_30 ) -> V_51 += 5 + strlen ( V_20 ) + V_15 ;
return;
V_43:
if ( F_25 ( V_19 -> V_26 ) )
if ( F_26 ( V_19 ) ) F_39 ( V_2 , F_25 ( V_19 -> V_26 ) , 1 , ( F_25 ( V_19 -> V_27 ) + 511 ) >> 9 ) ;
else F_10 ( V_2 , F_25 ( V_19 -> V_26 ) + ( ( F_25 ( V_19 -> V_27 ) + 511 ) >> 9 ) , V_5 - ( ( F_25 ( V_19 -> V_27 ) + 511 ) >> 9 ) ) ;
else V_19 -> V_26 = V_19 -> V_27 = F_33 ( 0 ) ;
}
