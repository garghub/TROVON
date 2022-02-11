char * F_1 ( const char * V_1 )
{
int V_2 = 0 ;
const char * V_3 = V_1 ;
char * V_4 ;
char * V_5 ;
if ( ! V_3 )
return NULL ;
while ( * V_3 ) {
const unsigned char V_6 = * V_3 ++ ;
if ( V_6 == '\\' )
V_2 += 2 ;
else if ( V_6 > ' ' && V_6 < 127 )
V_2 ++ ;
else
V_2 += 4 ;
}
V_2 ++ ;
V_4 = F_2 ( V_2 + 10 , V_7 ) ;
if ( ! V_4 )
return NULL ;
V_5 = V_4 ;
V_3 = V_1 ;
while ( * V_3 ) {
const unsigned char V_6 = * V_3 ++ ;
if ( V_6 == '\\' ) {
* V_4 ++ = '\\' ;
* V_4 ++ = '\\' ;
} else if ( V_6 > ' ' && V_6 < 127 ) {
* V_4 ++ = V_6 ;
} else {
* V_4 ++ = '\\' ;
* V_4 ++ = ( V_6 >> 6 ) + '0' ;
* V_4 ++ = ( ( V_6 >> 3 ) & 7 ) + '0' ;
* V_4 ++ = ( V_6 & 7 ) + '0' ;
}
}
return V_5 ;
}
char * F_3 ( struct V_8 * V_8 )
{
char * V_9 = NULL ;
char * V_10 = NULL ;
unsigned int V_11 = V_12 / 2 ;
struct V_13 * V_13 = V_8 -> V_13 ;
bool V_14 ;
if ( ! V_13 )
return NULL ;
V_14 = V_13 -> V_15 && F_4 ( V_13 -> V_15 -> V_16 ) ;
while ( 1 ) {
struct V_8 V_17 = { . V_18 = NULL , . V_13 = NULL } ;
char * V_19 ;
V_11 <<= 1 ;
F_5 ( V_9 ) ;
V_9 = F_6 ( V_11 , V_7 ) ;
if ( ! V_9 )
break;
if ( V_13 -> V_20 && V_13 -> V_20 -> V_21 == V_22 ) {
struct V_23 * V_23 = V_13 -> V_15 ;
struct V_24 * V_25 = V_23 ? F_7 ( V_23 ) : NULL ;
struct V_25 * V_26 = V_25 ? V_25 -> V_26 : NULL ;
if ( V_26 ) {
snprintf ( V_9 , V_11 - 1 , L_1
L_2 , V_26 -> V_27 ,
V_26 -> V_28 , V_26 -> V_29 ) ;
} else {
snprintf ( V_9 , V_11 - 1 , L_3 ) ;
}
V_10 = F_1 ( V_9 ) ;
break;
}
if ( V_13 -> V_30 && V_13 -> V_30 -> V_31 ) {
V_19 = V_13 -> V_30 -> V_31 ( V_13 , V_9 , V_11 - 1 ) ;
if ( F_8 ( V_19 ) )
continue;
V_10 = F_1 ( V_19 ) ;
break;
}
if ( ! V_8 -> V_18 )
break;
V_19 = F_9 ( V_8 , & V_17 , V_9 , V_11 ) ;
if ( ! F_8 ( V_19 ) && ( V_8 -> V_18 -> V_32 & V_33 ) &&
( V_8 -> V_18 -> V_34 -> V_21 == V_35 ) ) {
V_19 -= 5 ;
if ( V_19 >= V_9 )
memcpy ( V_19 , L_4 , 5 ) ;
else
V_19 = F_10 ( - V_36 ) ;
}
if ( F_8 ( V_19 ) )
continue;
V_10 = F_1 ( V_19 ) ;
break;
}
F_5 ( V_9 ) ;
if ( ! V_10 )
F_11 ( V_37 ) ;
else if ( V_14 && * V_10 ) {
char * V_19 = V_10 + strlen ( V_10 ) - 1 ;
if ( * V_19 != '/' )
* ++ V_19 = '/' ;
}
return V_10 ;
}
char * F_12 ( const char * V_38 )
{
struct V_8 V_8 ;
if ( V_38 && F_13 ( V_38 , 0 , & V_8 ) == 0 ) {
char * V_9 = F_3 ( & V_8 ) ;
F_14 ( & V_8 ) ;
return V_9 ;
}
return NULL ;
}
