int F_1 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 ;
T_3 V_8 = 0 ;
T_4 V_9 = ( T_4 ) V_1 ;
char * V_10 = F_2 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_14 V_15 * ) V_10 ,
V_11 , & V_8 ) ;
F_4 ( V_5 ) ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_9 -> V_16 ,
V_17 , V_18 ,
V_19 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_9 -> V_16 ,
V_17 , V_18 ,
V_19 ,
L_2 ) ;
}
break;
}
V_6 = F_8 ( V_9 , V_4 , V_10 , V_7 ) ;
if ( V_6 ) {
F_7 ( V_9 -> V_16 ,
V_20 , 0 , 0 ,
L_3 , V_6 ) ;
break;
}
V_4 += V_11 ;
}
F_9 ( V_10 ) ;
return V_6 ;
}
int F_10 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
char * V_10 , * V_21 ;
unsigned int V_22 = 0 ;
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 , V_23 = 0 ;
T_3 V_8 = 0 ;
static int V_24 ;
INT V_25 = V_26 ;
T_4 V_9 = ( T_4 ) V_1 ;
int V_27 ;
V_10 = F_2 ( V_11 , V_28 ) ;
V_21 = F_2 ( V_11 , V_28 ) ;
if ( ! V_10 || ! V_21 ) {
F_9 ( V_10 ) ;
F_9 ( V_21 ) ;
return - V_13 ;
}
V_23 = ( V_4 == V_29 ) ? 1 : 0 ;
memset ( V_21 , 0 , V_11 ) ;
memset ( V_10 , 0 , V_11 ) ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_14 V_15 * ) V_10 , V_11 , & V_8 ) ;
F_4 ( V_5 ) ;
V_24 ++ ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_2 ) ;
}
break;
}
V_27 = F_11 ( V_9 , V_4 , V_21 , V_7 ) ;
if ( V_27 < 0 ) {
V_25 = V_27 ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_4 , V_7 , V_22 ) ;
goto exit;
}
V_22 ++ ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_21 , V_10 , V_7 ) ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_6 , V_7 ) ;
V_25 = - V_30 ;
goto exit;
}
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_21 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_21 [ V_7 ] ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_25 = - V_30 ;
goto exit;
}
V_7 -= 4 ;
}
}
V_4 += V_11 ;
}
exit:
F_9 ( V_10 ) ;
F_9 ( V_21 ) ;
return V_25 ;
}
static int F_12 ( T_5 V_31 , T_6 * V_32 )
{
int V_33 = V_26 ;
T_7 V_34 = 0 ;
if ( V_31 -> V_35 == NULL ) {
V_31 -> V_35 = F_2 ( sizeof( V_36 ) , V_12 ) ;
if ( V_31 -> V_35 == NULL )
return - V_13 ;
}
if ( V_32 -> V_37 != sizeof( V_36 ) )
return - V_30 ;
V_33 = F_13 ( V_31 -> V_35 , V_32 -> V_38 , V_32 -> V_37 ) ;
if ( V_33 ) {
F_9 ( V_31 -> V_35 ) ;
V_31 -> V_35 = NULL ;
return - V_39 ;
}
F_14 ( V_31 ) ;
F_15 ( V_31 ) ;
V_33 = F_16 ( V_31 ) ;
if ( V_33 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_9 ) ;
return V_33 ;
}
if ( V_31 -> V_40 . V_41 & V_42 ) {
V_31 -> V_40 . V_43 = FALSE ;
V_31 -> V_44 = V_45 ;
F_17 ( & V_31 -> V_40 . V_46 ) ;
}
if ( V_31 -> V_40 . V_41 & V_42 ) {
V_31 -> V_44 = V_47 ;
F_17 ( & V_31 -> V_40 . V_46 ) ;
}
V_33 = F_18 ( V_31 ) ;
if ( V_33 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_10 ) ;
return V_33 ;
}
V_34 = 0 ;
F_19 ( V_31 , V_48 - 4 , & V_34 , sizeof( V_34 ) ) ;
F_19 ( V_31 , V_48 - 8 , & V_34 , sizeof( V_34 ) ) ;
if ( V_31 -> V_49 == V_50 ) {
V_33 = F_20 ( V_31 ) ;
if ( V_33 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_11 , V_33 ) ;
return V_33 ;
}
}
V_33 = F_21 ( V_31 , ( V_51 ) V_31 -> V_35 , sizeof( V_36 ) , V_29 ) ;
if ( V_33 )
F_7 ( V_31 , V_17 , V_18 , V_19 , L_12 ) ;
else
V_31 -> V_52 = TRUE ;
return V_33 ;
}
static int F_22 ( unsigned char * V_53 , unsigned char * V_10 , unsigned int V_7 )
{
int V_33 = V_26 ;
T_5 V_31 = F_23 ( V_54 ) ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_53 , V_10 , V_7 ) )
V_33 = - V_55 ;
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_53 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_13 ) ;
F_7 ( V_31 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_53 [ V_7 ] ) ;
F_7 ( V_31 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_33 = - V_55 ;
break;
}
V_7 -= 4 ;
}
}
return V_33 ;
}
int F_24 ( T_5 V_31 , T_6 * V_32 )
{
int V_33 = V_26 ;
V_51 V_10 = NULL ;
F_25 ( & V_31 -> V_56 , FALSE ) ;
if ( ! V_31 -> V_52 && V_32 -> V_57 != V_29 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_14 ) ;
return - V_55 ;
}
if ( V_32 -> V_57 == V_29 ) {
V_33 = F_12 ( V_31 , V_32 ) ;
} else {
V_10 = F_26 ( V_32 -> V_37 , V_12 ) ;
if ( V_10 == NULL ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_15 ) ;
return - V_13 ;
}
V_33 = F_13 ( V_10 , V_32 -> V_38 , V_32 -> V_37 ) ;
if ( V_33 != V_26 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_16 ) ;
V_33 = - V_39 ;
goto error;
}
V_33 = F_21 ( V_31 ,
V_10 ,
V_32 -> V_37 ,
V_32 -> V_57 ) ;
if ( V_33 != V_26 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_17 , V_33 ) ;
goto error;
}
}
error:
F_9 ( V_10 ) ;
return V_33 ;
}
static INT F_27 ( T_5 V_31 , V_51 V_58 , T_8 V_37 , T_9 V_57 )
{
unsigned int V_7 = 0 ;
int V_33 = V_26 ;
V_7 = V_37 ;
while ( V_37 ) {
V_7 = F_28 ( V_37 , V_11 ) ;
V_33 = F_29 ( V_31 , V_57 , V_58 , V_7 ) ;
if ( V_33 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_18 , V_33 ) ;
break;
}
V_57 += V_7 ;
V_37 -= V_7 ;
V_58 += V_7 ;
}
return V_33 ;
}
static INT F_30 ( T_5 V_31 , V_51 V_58 , T_8 V_37 , T_9 V_57 )
{
T_8 V_7 = V_37 ;
INT V_33 = V_26 ;
V_51 V_53 = F_26 ( V_11 , V_12 ) ;
int V_27 ;
if ( NULL == V_53 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_19 ) ;
return - V_13 ;
}
while ( V_37 && ! V_33 ) {
V_7 = F_28 ( V_37 , V_11 ) ;
V_27 = F_31 ( V_31 , V_57 , V_53 , V_7 ) ;
if ( V_27 < 0 ) {
V_33 = V_27 ;
F_7 ( V_31 , V_17 , V_18 , V_19 , L_20 , V_33 ) ;
break;
}
V_33 = F_22 ( V_53 , V_58 , V_7 ) ;
if ( V_26 != V_33 )
break;
V_57 += V_7 ;
V_37 -= V_7 ;
V_58 += V_7 ;
}
F_9 ( V_53 ) ;
return V_33 ;
}
INT F_21 ( T_5 V_31 , unsigned char * V_58 , unsigned int V_37 , unsigned long V_57 )
{
INT V_59 = V_26 ;
V_59 = F_27 ( V_31 , V_58 , V_37 , V_57 ) ;
if ( V_59 != V_26 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_21 ) ;
goto error;
}
V_59 = F_30 ( V_31 , V_58 , V_37 , V_57 ) ;
if ( V_59 != V_26 ) {
F_7 ( V_31 , V_17 , V_18 , V_19 , L_22 ) ;
goto error;
}
error:
return V_59 ;
}
