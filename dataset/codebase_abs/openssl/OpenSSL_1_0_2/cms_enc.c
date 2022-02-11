T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
T_3 * V_3 ;
const T_4 * V_4 ;
T_5 * V_5 = V_1 -> V_6 ;
unsigned char V_7 [ V_8 ] , * V_9 = NULL ;
unsigned char * V_10 = NULL ;
T_6 V_11 = 0 ;
int V_12 = 0 ;
int V_13 , V_14 = 0 ;
V_13 = V_1 -> V_15 ? 1 : 0 ;
V_2 = F_2 ( F_3 () ) ;
if ( ! V_2 ) {
F_4 ( V_16 , V_17 ) ;
return NULL ;
}
F_5 ( V_2 , & V_3 ) ;
if ( V_13 ) {
V_4 = V_1 -> V_15 ;
if ( V_1 -> V_18 )
V_1 -> V_15 = NULL ;
} else {
V_4 = F_6 ( V_5 -> V_19 ) ;
if ( ! V_4 ) {
F_4 ( V_16 , V_20 ) ;
goto V_21;
}
}
if ( F_7 ( V_3 , V_4 , NULL , NULL , NULL , V_13 ) <= 0 ) {
F_4 ( V_16 ,
V_22 ) ;
goto V_21;
}
if ( V_13 ) {
int V_23 ;
V_5 -> V_19 = F_8 ( F_9 ( V_3 ) ) ;
V_23 = F_10 ( V_3 ) ;
if ( V_23 > 0 ) {
if ( F_11 ( V_7 , V_23 ) <= 0 )
goto V_21;
V_9 = V_7 ;
}
} else if ( F_12 ( V_3 , V_5 -> V_24 ) <= 0 ) {
F_4 ( V_16 ,
V_25 ) ;
goto V_21;
}
V_11 = F_13 ( V_3 ) ;
if ( ! V_13 || ! V_1 -> V_18 ) {
V_10 = F_14 ( V_11 ) ;
if ( ! V_10 ) {
F_4 ( V_16 , V_17 ) ;
goto V_21;
}
if ( F_15 ( V_3 , V_10 ) <= 0 )
goto V_21;
}
if ( ! V_1 -> V_18 ) {
V_1 -> V_18 = V_10 ;
V_1 -> V_26 = V_11 ;
V_10 = NULL ;
if ( V_13 )
V_14 = 1 ;
else
F_16 () ;
}
if ( V_1 -> V_26 != V_11 ) {
if ( F_17 ( V_3 , V_1 -> V_26 ) <= 0 ) {
if ( V_13 || V_1 -> V_27 ) {
F_4 ( V_16 ,
V_28 ) ;
goto V_21;
} else {
F_18 ( V_1 -> V_18 , V_1 -> V_26 ) ;
F_19 ( V_1 -> V_18 ) ;
V_1 -> V_18 = V_10 ;
V_1 -> V_26 = V_11 ;
V_10 = NULL ;
F_16 () ;
}
}
}
if ( F_7 ( V_3 , NULL , NULL , V_1 -> V_18 , V_9 , V_13 ) <= 0 ) {
F_4 ( V_16 ,
V_22 ) ;
goto V_21;
}
if ( V_9 ) {
V_5 -> V_24 = F_20 () ;
if ( ! V_5 -> V_24 ) {
F_4 ( V_16 , V_17 ) ;
goto V_21;
}
if ( F_21 ( V_3 , V_5 -> V_24 ) <= 0 ) {
F_4 ( V_16 ,
V_25 ) ;
goto V_21;
}
}
V_12 = 1 ;
V_21:
if ( V_1 -> V_18 && ! V_14 ) {
F_18 ( V_1 -> V_18 , V_1 -> V_26 ) ;
F_19 ( V_1 -> V_18 ) ;
V_1 -> V_18 = NULL ;
}
if ( V_10 ) {
F_18 ( V_10 , V_11 ) ;
F_19 ( V_10 ) ;
}
if ( V_12 )
return V_2 ;
F_22 ( V_2 ) ;
return NULL ;
}
int F_23 ( T_2 * V_1 ,
const T_4 * V_15 ,
const unsigned char * V_18 , T_6 V_26 )
{
V_1 -> V_15 = V_15 ;
if ( V_18 ) {
V_1 -> V_18 = F_14 ( V_26 ) ;
if ( ! V_1 -> V_18 )
return 0 ;
memcpy ( V_1 -> V_18 , V_18 , V_26 ) ;
}
V_1 -> V_26 = V_26 ;
if ( V_15 )
V_1 -> V_29 = F_8 ( V_30 ) ;
return 1 ;
}
int F_24 ( T_7 * V_31 , const T_4 * V_4 ,
const unsigned char * V_18 , T_6 V_26 )
{
T_2 * V_1 ;
if ( ! V_18 || ! V_26 ) {
F_4 ( V_32 , V_33 ) ;
return 0 ;
}
if ( V_4 ) {
V_31 -> V_34 . V_35 = F_25 ( V_36 ) ;
if ( ! V_31 -> V_34 . V_35 ) {
F_4 ( V_32 , V_17 ) ;
return 0 ;
}
V_31 -> V_29 = F_8 ( V_37 ) ;
V_31 -> V_34 . V_35 -> V_38 = 0 ;
} else if ( F_26 ( V_31 -> V_29 ) != V_37 ) {
F_4 ( V_32 , V_39 ) ;
return 0 ;
}
V_1 = V_31 -> V_34 . V_35 -> V_40 ;
return F_23 ( V_1 , V_4 , V_18 , V_26 ) ;
}
T_1 * F_27 ( T_7 * V_31 )
{
V_36 * V_13 = V_31 -> V_34 . V_35 ;
if ( V_13 -> V_40 -> V_15 && V_13 -> V_41 )
V_13 -> V_38 = 2 ;
return F_1 ( V_13 -> V_40 ) ;
}
