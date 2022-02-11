static int F_1 ( unsigned char * * V_1 , long * V_2 , int V_3 )
{
const unsigned char * V_4 = * V_1 ;
int V_5 , V_6 , V_7 ;
long V_8 ;
V_5 = F_2 ( & V_4 , & V_8 , & V_6 , & V_7 , * V_2 ) ;
if ( V_5 & 0x80 )
return 0 ;
if ( V_6 != V_3 || V_7 != V_9 )
return 0 ;
if ( V_6 == V_10 )
V_4 += V_8 ;
* V_2 -= V_4 - * V_1 ;
* V_1 = ( unsigned char * ) V_4 ;
return 1 ;
}
static int F_3 ( unsigned char * * V_11 , unsigned char * * V_12 ,
T_1 * V_13 , T_2 V_14 ,
const unsigned char * V_15 , T_2 V_16 )
{
unsigned char * V_17 ;
int V_18 ;
long V_19 ;
static unsigned char V_20 [ 4 ] = { 0xF3 , 0x17 , 0x22 , 0x53 } ;
T_3 V_21 ;
T_4 V_22 , V_23 , * V_24 ;
T_5 V_25 ;
if ( V_16 > V_26 || V_14 > V_26 )
return 0 ;
V_22 . V_27 = V_20 ;
V_22 . V_28 = 4 ;
V_22 . V_29 = 0 ;
V_22 . type = V_30 ;
V_25 . type = V_30 ;
V_25 . V_31 . V_32 = & V_22 ;
V_21 . V_33 = V_13 ;
V_21 . V_34 = & V_25 ;
if ( V_15 ) {
V_23 . type = V_30 ;
V_23 . V_29 = 0 ;
V_23 . V_27 = ( unsigned char * ) V_15 ;
V_23 . V_28 = V_16 ;
V_24 = & V_23 ;
} else
V_24 = NULL ;
V_18 = F_4 ( V_11 , & V_21 , V_24 , V_14 ) ;
if ( V_18 <= 0 )
return 0 ;
V_17 = * V_11 ;
V_19 = V_18 ;
if ( ! F_1 ( & V_17 , & V_19 , V_35 ) )
return 0 ;
if ( ! F_1 ( & V_17 , & V_19 , V_35 ) )
return 0 ;
if ( ! F_1 ( & V_17 , & V_19 , V_10 ) )
return 0 ;
if ( ! F_1 ( & V_17 , & V_19 , V_30 ) )
return 0 ;
if ( F_5 ( V_17 , V_20 , 4 ) )
return 0 ;
* V_12 = V_17 ;
return V_18 ;
}
int F_6 ( unsigned char * V_36 , T_2 V_14 ,
const unsigned char * V_37 , T_2 V_38 ,
T_1 * V_13 ,
const unsigned char * V_15 , T_2 V_16 , const T_6 * V_39 )
{
T_7 * V_40 = NULL ;
int V_41 = 0 ;
unsigned int V_5 ;
T_2 V_42 ;
unsigned char * V_43 = NULL , * V_20 ;
int V_18 ;
if ( V_38 > V_26 )
return 0 ;
V_40 = F_7 () ;
if ( V_40 == NULL )
return 0 ;
V_42 = F_8 ( V_39 ) ;
V_18 = F_3 ( & V_43 , & V_20 , V_13 , V_14 , V_15 , V_16 ) ;
if ( V_18 == 0 )
goto V_44;
for ( V_5 = 1 ; ; V_5 ++ ) {
unsigned char V_45 [ V_46 ] ;
if ( ! F_9 ( V_40 , V_39 , NULL )
|| ! F_10 ( V_40 , V_37 , V_38 ) )
goto V_44;
V_20 [ 3 ] = V_5 & 0xFF ;
V_20 [ 2 ] = ( V_5 >> 8 ) & 0xFF ;
V_20 [ 1 ] = ( V_5 >> 16 ) & 0xFF ;
V_20 [ 0 ] = ( V_5 >> 24 ) & 0xFF ;
if ( ! F_10 ( V_40 , V_43 , V_18 ) )
goto V_44;
if ( V_14 >= V_42 ) {
if ( ! F_11 ( V_40 , V_36 , NULL ) )
goto V_44;
V_14 -= V_42 ;
if ( V_14 == 0 )
break;
V_36 += V_42 ;
} else {
if ( ! F_11 ( V_40 , V_45 , NULL ) )
goto V_44;
memcpy ( V_36 , V_45 , V_14 ) ;
F_12 ( V_45 , V_42 ) ;
break;
}
}
V_41 = 1 ;
V_44:
F_13 ( V_43 ) ;
F_14 ( V_40 ) ;
return V_41 ;
}
