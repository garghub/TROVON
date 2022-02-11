static unsigned int F_1 ( const char * V_1 ,
unsigned int V_2 )
{
unsigned int V_3 ;
char V_4 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_4 = V_1 [ V_3 ] ;
if ( V_4 == ' ' ) continue;
if ( V_4 == '\t' ) continue;
if ( V_4 == '\n' ) continue;
break;
}
return V_3 ;
}
static unsigned int F_2 ( const char * V_1 ,
unsigned int V_2 )
{
unsigned int V_3 ;
char V_4 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_4 = V_1 [ V_3 ] ;
if ( V_4 == ' ' ) break;
if ( V_4 == '\t' ) break;
if ( V_4 == '\n' ) break;
}
return V_3 ;
}
static unsigned int F_3 ( const char * V_1 , unsigned int V_2 ,
const char * * V_5 ,
unsigned int * V_6 )
{
const char * V_7 ;
unsigned int V_8 = 0 ;
unsigned int V_9 ;
unsigned int V_3 ;
V_7 = NULL ;
V_9 = 0 ;
V_3 = F_1 ( V_1 , V_2 ) ;
V_8 += V_3 ; V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_2 ) goto V_10;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( ! V_3 ) goto V_10;
V_7 = V_1 ;
V_9 = V_3 ;
V_8 += V_3 ; V_2 -= V_3 ; V_1 += V_3 ;
V_10:
* V_5 = V_7 ;
* V_6 = V_9 ;
return V_8 ;
}
static int F_4 ( const char * V_1 , unsigned int V_2 ,
T_1 * V_11 )
{
T_1 V_12 = 0 ;
int V_13 = 10 ;
if ( ( V_2 >= 2 ) && ( V_1 [ 0 ] == '0' ) &&
( ( V_1 [ 1 ] == 'x' ) || ( V_1 [ 1 ] == 'X' ) ) ) {
V_13 = 16 ;
V_2 -= 2 ;
V_1 += 2 ;
} else if ( ( V_2 >= 1 ) && ( V_1 [ 0 ] == '0' ) ) {
V_13 = 8 ;
}
while ( V_2 -- ) {
int V_14 = F_5 ( * V_1 ++ ) ;
if ( V_14 < 0 || V_14 >= V_13 )
return - V_15 ;
V_12 *= V_13 ;
V_12 += V_14 ;
}
* V_11 = V_12 ;
return 0 ;
}
static int F_6 ( const char * V_1 , unsigned int V_2 ,
const char * V_16 )
{
unsigned int V_17 ;
if ( ! V_16 ) return 0 ;
V_17 = strlen ( V_16 ) ;
if ( V_17 != V_2 ) return 0 ;
return ! memcmp ( V_1 , V_16 , V_17 ) ;
}
int F_7 ( struct V_18 * V_19 , char * V_1 , unsigned int V_20 )
{
int V_21 = 0 ;
int V_22 ;
V_22 = F_8 ( V_1 , V_20 , L_1 ,
F_9 ( V_19 ) ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
V_22 = F_8 ( V_1 , V_20 , L_2 ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
V_22 = F_10 ( V_19 , V_1 , V_20 ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
return V_21 ;
}
int F_11 ( struct V_18 * V_19 ,
char * V_1 , unsigned int V_20 )
{
int V_21 = 0 ;
int V_22 ;
int V_23 ;
T_1 V_24 , V_25 , V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
V_23 = F_12 ( V_19 ) ;
V_22 = F_8 ( V_1 , V_20 , L_3 ,
( V_23 < 0 ? L_4 : ( V_23 ? L_5 : L_6 ) ) ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
V_24 = 0 ; V_25 = 0 ; V_26 = 0 ;
F_13 ( V_19 , & V_24 ) ;
F_14 ( V_19 , & V_26 ) ;
F_15 ( V_19 , & V_25 ) ;
V_22 = F_8 ( V_1 , V_20 , L_7 ,
V_24 , V_25 , V_26 ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
V_22 = F_8 ( V_1 , V_20 , L_8 ,
F_16 ( V_19 ) ? L_9 : L_10 ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
V_30 = F_17 ( V_19 ) ;
if ( V_30 ) {
F_18 ( V_30 , & V_28 , 0 ) ;
V_22 = F_8 (
V_1 , V_20 ,
L_11 ,
V_28 . V_31 ,
V_28 . V_32 ,
V_28 . V_33 ,
V_28 . V_34 ,
V_28 . V_35 ,
V_28 . V_36 ) ;
V_21 += V_22 ; V_20 -= V_22 ; V_1 += V_22 ;
}
return V_21 ;
}
static int F_19 ( struct V_18 * V_19 , const char * V_1 ,
unsigned int V_2 )
{
const char * V_7 ;
unsigned int V_9 ;
unsigned int V_3 ;
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( ! V_3 ) return 0 ;
V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_7 ) return 0 ;
F_20 ( V_37 , L_12 , V_9 , V_7 ) ;
if ( F_6 ( V_7 , V_9 , L_13 ) ) {
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( ! V_3 ) return - V_15 ;
V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_7 ) return - V_15 ;
if ( F_6 ( V_7 , V_9 , L_14 ) ) {
F_21 ( V_19 , ! 0 ) ;
F_21 ( V_19 , 0 ) ;
return 0 ;
} else if ( F_6 ( V_7 , V_9 , L_15 ) ) {
F_22 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_16 ) ) {
return F_23 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_17 ) ) {
return F_24 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_18 ) ) {
return F_25 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_19 ) ) {
return F_26 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_20 ) ) {
return F_27 ( V_19 ) ;
} else if ( F_6 ( V_7 , V_9 , L_21 ) ) {
F_18 ( F_17 ( V_19 ) ,
NULL , ! 0 ) ;
return 0 ;
}
return - V_15 ;
} else if ( F_6 ( V_7 , V_9 , L_22 ) ) {
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( ! V_3 ) return - V_15 ;
V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_7 ) return - V_15 ;
if ( F_6 ( V_7 , V_9 , L_23 ) ) {
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( V_3 && V_7 ) {
V_2 -= V_3 ; V_1 += V_3 ;
if ( F_6 ( V_7 , V_9 ,
L_24 ) ) {
F_28 ( V_19 , 2 , ! 0 ) ;
} else if ( F_6 ( V_7 , V_9 ,
L_25 ) ) {
F_28 ( V_19 , 0 , ! 0 ) ;
} else if ( F_6 ( V_7 , V_9 ,
L_26 ) ) {
F_28 ( V_19 , 1 , ! 0 ) ;
} else {
return - V_15 ;
}
}
F_28 ( V_19 , 0 , ! 0 ) ;
return 0 ;
} else if ( F_6 ( V_7 , V_9 , L_27 ) ) {
F_28 ( V_19 , 0 , 0 ) ;
return 0 ;
} else {
return - V_15 ;
}
} else if ( F_6 ( V_7 , V_9 , L_28 ) ) {
int V_38 = 0 ;
int V_23 ;
T_1 V_39 , V_14 ;
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( ! V_3 ) return - V_15 ;
V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_7 ) return - V_15 ;
if ( F_6 ( V_7 , V_9 , L_29 ) ) {
V_38 = ! 0 ;
} else if ( ! F_6 ( V_7 , V_9 , L_30 ) ) {
return - V_15 ;
}
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( ! V_3 ) return - V_15 ;
V_2 -= V_3 ; V_1 += V_3 ;
if ( ! V_7 ) return - V_15 ;
V_23 = F_4 ( V_7 , V_9 , & V_39 ) ;
if ( V_23 ) return V_23 ;
V_3 = F_3 ( V_1 , V_2 , & V_7 , & V_9 ) ;
if ( V_7 ) {
V_23 = F_4 ( V_7 , V_9 , & V_14 ) ;
if ( V_23 ) return V_23 ;
} else {
V_14 = V_39 ;
V_39 = 0xffffffff ;
}
if ( V_38 ) {
V_23 = F_29 ( V_19 , V_39 , V_14 ) ;
} else {
V_23 = F_30 ( V_19 , V_39 , V_14 ) ;
}
return V_23 ;
}
F_20 ( V_37 ,
L_31 , V_9 , V_7 ) ;
return - V_15 ;
}
int F_31 ( struct V_18 * V_19 , const char * V_1 ,
unsigned int V_2 )
{
unsigned int V_21 = 0 ;
int V_23 ;
while ( V_2 ) {
for ( V_21 = 0 ; V_21 < V_2 ; V_21 ++ ) {
if ( V_1 [ V_21 ] == '\n' ) break;
}
V_23 = F_19 ( V_19 , V_1 , V_21 ) ;
if ( V_23 < 0 ) return V_23 ;
if ( V_21 < V_2 ) V_21 ++ ;
V_1 += V_21 ;
V_2 -= V_21 ;
}
return 0 ;
}
