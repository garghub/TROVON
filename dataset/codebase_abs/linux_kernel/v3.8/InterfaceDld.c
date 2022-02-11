int F_1 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 ;
T_3 V_8 = 0 ;
struct V_9 * V_10 = (struct V_9 * ) V_1 ;
char * V_11 = F_2 ( V_12 , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_15 V_16 * ) V_11 ,
V_12 , & V_8 ) ;
F_4 ( V_5 ) ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_10 -> V_17 ,
V_18 , V_19 ,
V_20 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_10 -> V_17 ,
V_18 , V_19 ,
V_20 ,
L_2 ) ;
}
break;
}
V_6 = F_8 ( V_10 , V_4 , V_11 , V_7 ) ;
if ( V_6 ) {
F_7 ( V_10 -> V_17 ,
V_21 , 0 , 0 ,
L_3 , V_6 ) ;
break;
}
V_4 += V_12 ;
}
F_9 ( V_11 ) ;
return V_6 ;
}
int F_10 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
char * V_11 , * V_22 ;
unsigned int V_23 = 0 ;
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 , V_24 = 0 ;
T_3 V_8 = 0 ;
static int V_25 ;
INT V_26 = V_27 ;
struct V_9 * V_10 = (struct V_9 * ) V_1 ;
int V_28 ;
V_11 = F_2 ( V_12 , V_29 ) ;
V_22 = F_2 ( V_12 , V_29 ) ;
if ( ! V_11 || ! V_22 ) {
F_9 ( V_11 ) ;
F_9 ( V_22 ) ;
return - V_14 ;
}
V_24 = ( V_4 == V_30 ) ? 1 : 0 ;
memset ( V_22 , 0 , V_12 ) ;
memset ( V_11 , 0 , V_12 ) ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_15 V_16 * ) V_11 , V_12 , & V_8 ) ;
F_4 ( V_5 ) ;
V_25 ++ ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_2 ) ;
}
break;
}
V_28 = F_11 ( V_10 , V_4 , V_22 , V_7 ) ;
if ( V_28 < 0 ) {
V_26 = V_28 ;
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_4 , V_7 , V_23 ) ;
goto exit;
}
V_23 ++ ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_22 , V_11 , V_7 ) ) {
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_5 , V_25 ) ;
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_6 , V_7 ) ;
V_26 = - V_31 ;
goto exit;
}
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_22 [ V_7 ] != * ( unsigned int * ) & V_11 [ V_7 ] ) {
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_5 , V_25 ) ;
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_7 , * ( unsigned int * ) & V_11 [ V_7 ] , * ( unsigned int * ) & V_22 [ V_7 ] ) ;
F_7 ( V_10 -> V_17 , V_18 , V_19 , V_20 , L_8 , V_7 ) ;
V_26 = - V_31 ;
goto exit;
}
V_7 -= 4 ;
}
}
V_4 += V_12 ;
}
exit:
F_9 ( V_11 ) ;
F_9 ( V_22 ) ;
return V_26 ;
}
static int F_12 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
int V_36 = V_27 ;
T_4 V_37 = 0 ;
if ( V_33 -> V_38 == NULL ) {
V_33 -> V_38 = F_2 ( sizeof( V_39 ) , V_13 ) ;
if ( V_33 -> V_38 == NULL )
return - V_14 ;
}
if ( V_35 -> V_40 != sizeof( V_39 ) )
return - V_31 ;
V_36 = F_13 ( V_33 -> V_38 , V_35 -> V_41 , V_35 -> V_40 ) ;
if ( V_36 ) {
F_9 ( V_33 -> V_38 ) ;
V_33 -> V_38 = NULL ;
return - V_42 ;
}
F_14 ( V_33 ) ;
F_15 ( V_33 ) ;
V_36 = F_16 ( V_33 ) ;
if ( V_36 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_9 ) ;
return V_36 ;
}
if ( V_33 -> V_43 . V_44 & V_45 ) {
V_33 -> V_43 . V_46 = FALSE ;
V_33 -> V_47 = V_48 ;
F_17 ( & V_33 -> V_43 . V_49 ) ;
}
if ( V_33 -> V_43 . V_44 & V_45 ) {
V_33 -> V_47 = V_50 ;
F_17 ( & V_33 -> V_43 . V_49 ) ;
}
V_36 = F_18 ( V_33 ) ;
if ( V_36 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_10 ) ;
return V_36 ;
}
V_37 = 0 ;
F_19 ( V_33 , V_51 - 4 , & V_37 , sizeof( V_37 ) ) ;
F_19 ( V_33 , V_51 - 8 , & V_37 , sizeof( V_37 ) ) ;
if ( V_33 -> V_52 == V_53 ) {
V_36 = F_20 ( V_33 ) ;
if ( V_36 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_11 , V_36 ) ;
return V_36 ;
}
}
V_36 = F_21 ( V_33 , ( V_54 ) V_33 -> V_38 , sizeof( V_39 ) , V_30 ) ;
if ( V_36 )
F_7 ( V_33 , V_18 , V_19 , V_20 , L_12 ) ;
else
V_33 -> V_55 = TRUE ;
return V_36 ;
}
static int F_22 ( unsigned char * V_56 , unsigned char * V_11 , unsigned int V_7 )
{
int V_36 = V_27 ;
struct V_32 * V_33 = F_23 ( V_57 ) ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_56 , V_11 , V_7 ) )
V_36 = - V_58 ;
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_56 [ V_7 ] != * ( unsigned int * ) & V_11 [ V_7 ] ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_13 ) ;
F_7 ( V_33 , V_18 , V_19 , V_20 , L_7 , * ( unsigned int * ) & V_11 [ V_7 ] , * ( unsigned int * ) & V_56 [ V_7 ] ) ;
F_7 ( V_33 , V_18 , V_19 , V_20 , L_8 , V_7 ) ;
V_36 = - V_58 ;
break;
}
V_7 -= 4 ;
}
}
return V_36 ;
}
int F_24 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
int V_36 = V_27 ;
V_54 V_11 = NULL ;
F_25 ( & V_33 -> V_59 , FALSE ) ;
if ( ! V_33 -> V_55 && V_35 -> V_60 != V_30 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_14 ) ;
return - V_58 ;
}
if ( V_35 -> V_60 == V_30 ) {
V_36 = F_12 ( V_33 , V_35 ) ;
} else {
V_11 = F_26 ( V_35 -> V_40 , V_13 ) ;
if ( V_11 == NULL ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_15 ) ;
return - V_14 ;
}
V_36 = F_13 ( V_11 , V_35 -> V_41 , V_35 -> V_40 ) ;
if ( V_36 != V_27 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_16 ) ;
V_36 = - V_42 ;
goto error;
}
V_36 = F_21 ( V_33 ,
V_11 ,
V_35 -> V_40 ,
V_35 -> V_60 ) ;
if ( V_36 != V_27 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_17 , V_36 ) ;
goto error;
}
}
error:
F_9 ( V_11 ) ;
return V_36 ;
}
static INT F_27 ( struct V_32 * V_33 , V_54 V_61 , T_5 V_40 , T_6 V_60 )
{
unsigned int V_7 = 0 ;
int V_36 = V_27 ;
V_7 = V_40 ;
while ( V_40 ) {
V_7 = F_28 ( V_40 , V_12 ) ;
V_36 = F_29 ( V_33 , V_60 , V_61 , V_7 ) ;
if ( V_36 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_18 , V_36 ) ;
break;
}
V_60 += V_7 ;
V_40 -= V_7 ;
V_61 += V_7 ;
}
return V_36 ;
}
static INT F_30 ( struct V_32 * V_33 , V_54 V_61 , T_5 V_40 , T_6 V_60 )
{
T_5 V_7 = V_40 ;
INT V_36 = V_27 ;
V_54 V_56 = F_26 ( V_12 , V_13 ) ;
int V_28 ;
if ( NULL == V_56 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_19 ) ;
return - V_14 ;
}
while ( V_40 && ! V_36 ) {
V_7 = F_28 ( V_40 , V_12 ) ;
V_28 = F_31 ( V_33 , V_60 , V_56 , V_7 ) ;
if ( V_28 < 0 ) {
V_36 = V_28 ;
F_7 ( V_33 , V_18 , V_19 , V_20 , L_20 , V_36 ) ;
break;
}
V_36 = F_22 ( V_56 , V_61 , V_7 ) ;
if ( V_27 != V_36 )
break;
V_60 += V_7 ;
V_40 -= V_7 ;
V_61 += V_7 ;
}
F_9 ( V_56 ) ;
return V_36 ;
}
INT F_21 ( struct V_32 * V_33 , unsigned char * V_61 , unsigned int V_40 , unsigned long V_60 )
{
INT V_62 = V_27 ;
V_62 = F_27 ( V_33 , V_61 , V_40 , V_60 ) ;
if ( V_62 != V_27 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_21 ) ;
goto error;
}
V_62 = F_30 ( V_33 , V_61 , V_40 , V_60 ) ;
if ( V_62 != V_27 ) {
F_7 ( V_33 , V_18 , V_19 , V_20 , L_22 ) ;
goto error;
}
error:
return V_62 ;
}
