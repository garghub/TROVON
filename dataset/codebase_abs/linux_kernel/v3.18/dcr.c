static struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * V_4 ;
const T_1 * V_5 ;
for ( V_3 = F_2 ( V_2 ) ; V_3 ; ) {
if ( F_3 ( V_3 , L_1 , NULL ) )
break;
V_5 = F_3 ( V_3 , L_2 , NULL ) ;
V_4 = V_3 ;
if ( V_5 == NULL )
V_3 = F_4 ( V_3 ) ;
else
V_3 = F_5 ( * V_5 ) ;
F_6 ( V_4 ) ;
}
return V_3 ;
}
bool F_7 ( T_2 V_6 )
{
if ( V_6 . type == V_7 )
return F_8 ( V_6 . V_6 . V_8 ) ;
else if ( V_6 . type == V_9 )
return F_9 ( V_6 . V_6 . V_10 ) ;
else
return 0 ;
}
T_2 F_10 ( struct V_1 * V_11 ,
unsigned int V_12 ,
unsigned int V_13 )
{
T_2 V_6 ;
struct V_1 * V_14 ;
const char * V_15 ;
V_6 . type = V_16 ;
V_14 = F_1 ( V_11 ) ;
if ( V_14 == NULL )
return V_6 ;
V_15 = F_3 ( V_14 , L_3 , NULL ) ;
F_11 ( L_4 , V_15 ) ;
if ( ! strcmp ( V_15 , L_5 ) ) {
V_6 . type = V_7 ;
V_6 . V_6 . V_8 = F_12 ( V_11 , V_12 , V_13 ) ;
} else if ( ! strcmp ( V_15 , L_6 ) ) {
V_6 . type = V_9 ;
V_6 . V_6 . V_10 = F_13 ( V_11 , V_12 , V_13 ) ;
}
F_6 ( V_14 ) ;
return V_6 ;
}
void F_14 ( T_2 V_6 , unsigned int V_13 )
{
if ( V_6 . type == V_7 )
F_15 ( V_6 . V_6 . V_8 , V_13 ) ;
else if ( V_6 . type == V_9 )
F_16 ( V_6 . V_6 . V_10 , V_13 ) ;
else
F_17 ( true ) ;
}
T_1 F_18 ( T_2 V_6 , unsigned int V_12 )
{
if ( V_6 . type == V_7 )
return F_19 ( V_6 . V_6 . V_8 , V_12 ) ;
else if ( V_6 . type == V_9 )
return F_20 ( V_6 . V_6 . V_10 , V_12 ) ;
else
F_17 ( true ) ;
return 0 ;
}
void F_21 ( T_2 V_6 , unsigned int V_12 , T_1 V_17 )
{
if ( V_6 . type == V_7 )
F_22 ( V_6 . V_6 . V_8 , V_12 , V_17 ) ;
else if ( V_6 . type == V_9 )
F_23 ( V_6 . V_6 . V_10 , V_12 , V_17 ) ;
else
F_17 ( true ) ;
}
unsigned int F_24 ( const struct V_1 * V_18 ,
unsigned int V_19 )
{
unsigned int V_20 ;
const T_1 * V_21 = F_3 ( V_18 , L_7 , & V_20 ) ;
if ( V_21 == NULL || V_20 & 1 || V_19 >= ( V_20 / 8 ) )
return 0 ;
return V_21 [ V_19 * 2 ] ;
}
unsigned int F_25 ( const struct V_1 * V_18 , unsigned int V_19 )
{
unsigned int V_20 ;
const T_1 * V_21 = F_3 ( V_18 , L_7 , & V_20 ) ;
if ( V_21 == NULL || V_20 & 1 || V_19 >= ( V_20 / 8 ) )
return 0 ;
return V_21 [ V_19 * 2 + 1 ] ;
}
static T_3 F_26 ( struct V_1 * V_11 ,
unsigned int V_12 ,
unsigned int * V_22 )
{
struct V_1 * V_14 ;
const T_1 * V_5 ;
unsigned int V_23 ;
T_3 V_24 = V_25 ;
V_14 = F_1 ( V_11 ) ;
if ( V_14 == NULL )
return V_25 ;
V_5 = F_3 ( V_14 , L_8 , NULL ) ;
V_23 = ( V_5 == NULL ) ? 0x10 : * V_5 ;
V_5 = F_3 ( V_14 , L_9 , NULL ) ;
if ( V_5 == NULL )
V_5 = F_3 ( V_14 , L_10 , NULL ) ;
if ( V_5 == NULL )
goto V_26;
V_24 = F_27 ( V_14 , V_5 ) ;
if ( V_24 != V_25 )
V_24 += ( T_3 ) ( V_23 ) * ( T_3 ) V_12 ;
if ( V_22 )
* V_22 = V_23 ;
V_26:
F_6 ( V_14 ) ;
return V_24 ;
}
T_4 F_13 ( struct V_1 * V_11 ,
unsigned int V_12 ,
unsigned int V_13 )
{
T_4 V_24 = { . V_27 = NULL , . V_23 = 0 , . V_28 = V_12 } ;
T_3 V_29 ;
F_11 ( L_11 ,
V_11 -> V_30 , V_12 , V_13 ) ;
V_29 = F_26 ( V_11 , V_12 , & V_24 . V_23 ) ;
F_11 ( L_12 ,
( unsigned long long ) V_29 , V_24 . V_23 ) ;
if ( V_29 == V_25 )
return V_24 ;
F_11 ( L_13 , V_13 * V_24 . V_23 ) ;
V_24 . V_27 = F_28 ( V_29 , V_13 * V_24 . V_23 ) ;
if ( V_24 . V_27 == NULL )
return V_24 ;
F_11 ( L_14 ,
V_24 . V_27 , V_24 . V_27 - V_12 * V_24 . V_23 ) ;
V_24 . V_27 -= V_12 * V_24 . V_23 ;
return V_24 ;
}
void F_16 ( T_4 V_6 , unsigned int V_13 )
{
T_4 V_31 = V_6 ;
if ( V_31 . V_27 == NULL )
return;
V_31 . V_27 += V_6 . V_28 * V_31 . V_23 ;
F_29 ( V_31 . V_27 ) ;
V_31 . V_27 = NULL ;
}
