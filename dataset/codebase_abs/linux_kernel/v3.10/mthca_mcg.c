static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , struct V_4 * V_5 ,
T_2 * V_6 , int * V_7 , int * V_8 )
{
struct V_4 * V_9 ;
struct V_10 * V_11 = V_5 -> V_12 ;
T_1 * V_13 ;
int V_14 ;
V_9 = F_2 ( V_2 , V_15 ) ;
if ( F_3 ( V_9 ) )
return - V_16 ;
V_13 = V_9 -> V_12 ;
memcpy ( V_13 , V_3 , 16 ) ;
V_14 = F_4 ( V_2 , V_9 , V_6 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_1 , V_14 ) ;
goto V_17;
}
if ( 0 )
F_6 ( V_2 , L_2 , V_3 , * V_6 ) ;
* V_8 = * V_6 ;
* V_7 = - 1 ;
do {
V_14 = F_7 ( V_2 , * V_8 , V_5 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_3 , V_14 ) ;
goto V_17;
}
if ( ! memcmp ( V_11 -> V_3 , V_18 , 16 ) ) {
if ( * V_8 != * V_6 ) {
F_5 ( V_2 , L_4 ) ;
V_14 = - V_19 ;
}
goto V_17;
}
if ( ! memcmp ( V_11 -> V_3 , V_3 , 16 ) )
goto V_17;
* V_7 = * V_8 ;
* V_8 = F_8 ( V_11 -> V_20 ) >> 6 ;
} while ( * V_8 );
* V_8 = - 1 ;
V_17:
F_9 ( V_2 , V_9 ) ;
return V_14 ;
}
int F_10 ( struct V_21 * V_22 , union V_23 * V_3 , T_2 V_24 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_25 ) ;
struct V_4 * V_9 ;
struct V_10 * V_11 ;
T_2 V_6 ;
int V_8 , V_7 ;
int V_26 = 0 ;
int V_27 ;
int V_14 ;
V_9 = F_2 ( V_2 , V_15 ) ;
if ( F_3 ( V_9 ) )
return F_12 ( V_9 ) ;
V_11 = V_9 -> V_12 ;
F_13 ( & V_2 -> V_28 . V_29 ) ;
V_14 = F_1 ( V_2 , V_3 -> V_30 , V_9 , & V_6 , & V_7 , & V_8 ) ;
if ( V_14 )
goto V_17;
if ( V_8 != - 1 ) {
if ( ! memcmp ( V_11 -> V_3 , V_18 , 16 ) )
memcpy ( V_11 -> V_3 , V_3 -> V_30 , 16 ) ;
} else {
V_26 = 1 ;
V_8 = F_14 ( & V_2 -> V_28 . V_31 ) ;
if ( V_8 == - 1 ) {
F_5 ( V_2 , L_5 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_14 = F_7 ( V_2 , V_8 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_3 , V_14 ) ;
goto V_17;
}
memset ( V_11 , 0 , sizeof *V_11 ) ;
memcpy ( V_11 -> V_3 , V_3 -> V_30 , 16 ) ;
}
for ( V_27 = 0 ; V_27 < V_32 ; ++ V_27 )
if ( V_11 -> V_33 [ V_27 ] == F_15 ( V_22 -> V_34 | ( 1 << 31 ) ) ) {
F_6 ( V_2 , L_6 ,
V_22 -> V_34 ) ;
V_14 = 0 ;
goto V_17;
} else if ( ! ( V_11 -> V_33 [ V_27 ] & F_15 ( 1 << 31 ) ) ) {
V_11 -> V_33 [ V_27 ] = F_15 ( V_22 -> V_34 | ( 1 << 31 ) ) ;
break;
}
if ( V_27 == V_32 ) {
F_5 ( V_2 , L_7 , V_8 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_14 = F_16 ( V_2 , V_8 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_8 , V_14 ) ;
V_14 = - V_19 ;
goto V_17;
}
if ( ! V_26 )
goto V_17;
V_14 = F_7 ( V_2 , V_7 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_9 , V_14 ) ;
goto V_17;
}
V_11 -> V_20 = F_15 ( V_8 << 6 ) ;
V_14 = F_16 ( V_2 , V_7 , V_9 ) ;
if ( V_14 )
F_5 ( V_2 , L_10 , V_14 ) ;
V_17:
if ( V_14 && V_26 && V_8 != - 1 ) {
F_17 ( V_8 < V_2 -> V_35 . V_36 ) ;
F_18 ( & V_2 -> V_28 . V_31 , V_8 ) ;
}
F_19 ( & V_2 -> V_28 . V_29 ) ;
F_9 ( V_2 , V_9 ) ;
return V_14 ;
}
int F_20 ( struct V_21 * V_22 , union V_23 * V_3 , T_2 V_24 )
{
struct V_1 * V_2 = F_11 ( V_22 -> V_25 ) ;
struct V_4 * V_9 ;
struct V_10 * V_11 ;
T_2 V_6 ;
int V_7 , V_8 ;
int V_27 , V_37 ;
int V_14 ;
V_9 = F_2 ( V_2 , V_15 ) ;
if ( F_3 ( V_9 ) )
return F_12 ( V_9 ) ;
V_11 = V_9 -> V_12 ;
F_13 ( & V_2 -> V_28 . V_29 ) ;
V_14 = F_1 ( V_2 , V_3 -> V_30 , V_9 , & V_6 , & V_7 , & V_8 ) ;
if ( V_14 )
goto V_17;
if ( V_8 == - 1 ) {
F_5 ( V_2 , L_11 , V_3 -> V_30 ) ;
V_14 = - V_19 ;
goto V_17;
}
for ( V_37 = - 1 , V_27 = 0 ; V_27 < V_32 ; ++ V_27 ) {
if ( V_11 -> V_33 [ V_27 ] == F_15 ( V_22 -> V_34 | ( 1 << 31 ) ) )
V_37 = V_27 ;
if ( ! ( V_11 -> V_33 [ V_27 ] & F_15 ( 1 << 31 ) ) )
break;
}
if ( V_37 == - 1 ) {
F_5 ( V_2 , L_12 , V_22 -> V_34 ) ;
V_14 = - V_19 ;
goto V_17;
}
V_11 -> V_33 [ V_37 ] = V_11 -> V_33 [ V_27 - 1 ] ;
V_11 -> V_33 [ V_27 - 1 ] = 0 ;
V_14 = F_16 ( V_2 , V_8 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_10 , V_14 ) ;
goto V_17;
}
if ( V_27 != 1 )
goto V_17;
if ( V_7 == - 1 ) {
int V_38 = F_8 ( V_11 -> V_20 ) >> 6 ;
if ( V_38 ) {
V_14 = F_7 ( V_2 , V_38 ,
V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_13 , V_14 ) ;
goto V_17;
}
} else
memset ( V_11 -> V_3 , 0 , 16 ) ;
V_14 = F_16 ( V_2 , V_8 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_10 , V_14 ) ;
goto V_17;
}
if ( V_38 ) {
F_17 ( V_38 < V_2 -> V_35 . V_36 ) ;
F_18 ( & V_2 -> V_28 . V_31 , V_38 ) ;
}
} else {
int V_39 = F_8 ( V_11 -> V_20 ) >> 6 ;
V_14 = F_7 ( V_2 , V_7 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_13 , V_14 ) ;
goto V_17;
}
V_11 -> V_20 = F_15 ( V_39 << 6 ) ;
V_14 = F_16 ( V_2 , V_7 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , L_10 , V_14 ) ;
goto V_17;
}
F_17 ( V_8 < V_2 -> V_35 . V_36 ) ;
F_18 ( & V_2 -> V_28 . V_31 , V_8 ) ;
}
V_17:
F_19 ( & V_2 -> V_28 . V_29 ) ;
F_9 ( V_2 , V_9 ) ;
return V_14 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_14 ;
int V_40 = V_2 -> V_35 . V_36 + V_2 -> V_35 . V_41 ;
V_14 = F_22 ( & V_2 -> V_28 . V_31 ,
V_40 ,
V_40 - 1 ,
V_2 -> V_35 . V_36 ) ;
if ( V_14 )
return V_14 ;
F_23 ( & V_2 -> V_28 . V_29 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_28 . V_31 ) ;
}
