static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = 0 ;
}
int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
V_9 = F_4 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 )
return - V_15 ;
F_2 ( & V_9 -> V_16 ) ;
F_5 ( & V_9 -> V_16 , V_17 ) ;
V_10 = F_6 ( & V_9 -> V_16 ) ;
V_13 = F_6 ( F_7 (
F_8 ( & V_9 -> V_16 ) ) ) ;
V_11 = F_8 ( & V_9 -> V_16 ) ;
for ( V_12 = 0 ; V_12 < V_10 / V_13 ; V_12 ++ )
V_11 = F_9 ( V_11 , & V_9 -> V_16 ) ;
for (; V_12 < V_10 ; V_12 ++ ) {
F_10 ( V_11 , & V_9 -> V_16 ) ;
V_11 = F_9 ( V_11 , & V_9 -> V_16 ) ;
}
V_7 -> V_18 = V_9 ;
return 0 ;
}
void F_11 ( struct V_6 * V_7 )
{
int V_19 = F_12 ( V_7 -> V_20 -> V_21 ) ;
struct V_8 * V_9 = V_7 -> V_18 ;
const struct V_22 * V_23 ;
int V_11 , V_10 , V_12 ;
if ( V_19 < 0 )
V_19 = F_13 () ;
V_7 -> V_19 = V_19 ;
F_14 ( & V_9 -> V_24 ) ;
F_1 ( & V_9 -> V_25 ) ;
F_1 ( & V_9 -> V_26 ) ;
F_1 ( & V_9 -> V_27 ) ;
V_23 = F_15 ( V_7 -> V_19 ) ;
if ( F_8 ( V_23 ) >= V_28 )
V_23 = F_16 ( 0 ) ;
F_17 ( & V_9 -> V_25 . V_3 , & V_9 -> V_16 , V_23 ) ;
V_10 = F_6 ( & V_9 -> V_25 . V_3 ) ;
V_11 = F_8 ( & V_9 -> V_25 . V_3 ) ;
if ( V_10 == 1 ) {
F_18 ( V_11 , & V_9 -> V_26 . V_3 ) ;
} else {
V_11 = F_9 ( V_11 , & V_9 -> V_25 . V_3 ) ;
for ( V_12 = 0 ; V_12 < V_7 -> V_29 - 1 ; V_12 ++ ) {
F_10 ( V_11 , & V_9 -> V_25 . V_3 ) ;
F_18 ( V_11 , & V_9 -> V_26 . V_3 ) ;
V_11 = F_9 ( V_11 , & V_9 -> V_25 . V_3 ) ;
if ( V_11 >= V_28 )
break;
}
}
F_5 ( & V_9 -> V_27 . V_3 , V_17 ) ;
}
void F_19 ( struct V_6 * V_7 )
{
F_20 ( V_7 -> V_18 ) ;
}
int F_21 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
int V_32 ;
T_1 V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 = NULL ;
struct V_36 * V_37 = NULL ;
char V_38 [ 64 ] ;
int V_39 = - 1 ;
V_38 [ 0 ] = '\0' ;
F_2 ( & V_31 -> V_3 ) ;
V_32 = F_22 ( & V_33 , V_14 ) ;
if ( ! V_32 )
return - V_15 ;
switch ( V_31 -> type ) {
case V_40 :
V_35 = (struct V_34 * ) V_31 -> V_41 ;
F_23 ( V_38 , 64 , L_1 , V_35 -> V_42 ) ;
case V_43 :
V_2 = & V_7 -> V_18 -> V_25 ;
break;
case V_44 :
V_37 = (struct V_36 * ) V_31 -> V_41 ;
if ( V_37 -> V_45 == V_46 ) {
V_2 = & V_7 -> V_18 -> V_25 ;
V_39 = F_8 ( & V_2 -> V_3 ) ;
} else {
V_2 = & V_7 -> V_18 -> V_26 ;
}
F_23 ( V_38 , 64 , L_2 , V_37 -> V_45 ) ;
break;
default:
F_24 ( V_7 , L_3 , V_31 -> type ) ;
return - V_47 ;
}
if ( V_39 == - 1 ) {
F_25 ( & V_7 -> V_18 -> V_24 ) ;
if ( F_26 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
F_27 ( V_33 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
V_39 = F_8 ( V_33 ) ;
F_18 ( V_39 , & V_2 -> V_4 ) ;
F_28 ( & V_7 -> V_18 -> V_24 ) ;
}
switch ( V_31 -> type ) {
case V_40 :
V_35 -> V_39 = V_39 ;
break;
case V_43 :
case V_44 :
case V_48 :
break;
}
F_18 ( V_39 , & V_31 -> V_3 ) ;
F_29 ( V_7 , L_4 ,
V_31 -> V_31 . V_49 , V_50 [ V_31 -> type ] ,
V_38 , V_39 ) ;
F_30 ( V_31 -> V_31 . V_49 , & V_31 -> V_3 ) ;
F_31 ( V_33 ) ;
return 0 ;
}
void F_32 ( struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = NULL ;
struct V_36 * V_37 ;
switch ( V_31 -> type ) {
case V_40 :
case V_43 :
V_2 = & V_7 -> V_18 -> V_25 ;
break;
case V_44 :
V_37 = (struct V_36 * ) V_31 -> V_41 ;
if ( V_37 -> V_45 != V_46 )
V_2 = & V_7 -> V_18 -> V_26 ;
break;
default:
return;
}
if ( V_2 ) {
F_25 ( & V_7 -> V_18 -> V_24 ) ;
F_27 ( & V_2 -> V_4 , & V_2 -> V_4 , & V_31 -> V_3 ) ;
if ( F_33 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_5 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_28 ( & V_7 -> V_18 -> V_24 ) ;
}
F_30 ( V_31 -> V_31 . V_49 , NULL ) ;
F_2 ( & V_31 -> V_3 ) ;
}
int F_34 ( struct V_6 * V_7 , int V_19 )
{
int V_39 = - 1 , V_32 ;
T_1 V_33 , V_3 , V_51 ;
const struct V_22 * V_52 ,
* V_53 = F_35 ( V_54 ) ;
struct V_1 * V_2 = & V_7 -> V_18 -> V_27 ;
if ( F_6 ( V_53 ) == 1 ) {
F_36 ( V_55 , L_5 ,
V_54 -> V_56 , V_54 -> V_57 ,
F_37 ( V_53 ) ) ;
V_39 = F_8 ( V_53 ) ;
F_18 ( V_39 , & V_2 -> V_4 ) ;
goto V_58;
} else if ( F_6 ( V_53 ) < F_6 ( & V_2 -> V_3 ) ) {
F_36 ( V_55 , L_6 ,
V_54 -> V_56 , V_54 -> V_57 ,
F_37 ( V_53 ) ) ;
goto V_58;
}
V_32 = F_22 ( & V_33 , V_14 ) ;
if ( ! V_32 )
goto V_58;
V_32 = F_22 ( & V_3 , V_14 ) ;
if ( ! V_32 )
goto V_59;
V_32 = F_22 ( & V_51 , V_14 ) ;
if ( ! V_32 )
goto V_60;
F_25 ( & V_7 -> V_18 -> V_24 ) ;
if ( F_26 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
F_5 ( V_51 , ( V_7 -> V_18 -> V_25 . V_5 ?
& V_7 -> V_18 -> V_25 . V_3 :
& V_7 -> V_18 -> V_25 . V_4 ) ) ;
F_38 ( V_51 , V_51 , ( V_7 -> V_18 -> V_26 . V_5 ?
& V_7 -> V_18 -> V_26 . V_3 :
& V_7 -> V_18 -> V_26 . V_4 ) ) ;
F_36 ( V_55 , L_7 ,
F_37 ( V_51 ) ) ;
if ( V_19 == - 1 )
V_19 = V_7 -> V_19 ;
V_52 = F_15 ( V_19 ) ;
F_36 ( V_55 , L_8 , V_19 ,
F_37 ( V_52 ) ) ;
F_27 ( V_33 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
F_36 ( V_55 , L_9 , F_37 ( V_33 ) ) ;
F_17 ( V_3 , V_33 , V_52 ) ;
F_36 ( V_55 , L_10 , F_37 ( V_3 ) ) ;
F_27 ( V_33 , V_3 , V_51 ) ;
if ( ! F_33 ( V_33 ) )
F_5 ( V_3 , V_33 ) ;
if ( F_33 ( V_3 ) ) {
F_27 ( V_33 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
F_27 ( V_3 , V_33 , V_52 ) ;
}
F_36 ( V_55 , L_11 ,
F_37 ( V_3 ) ) ;
V_39 = F_8 ( V_3 ) ;
if ( V_39 >= V_28 )
V_39 = - 1 ;
else
F_18 ( V_39 , & V_2 -> V_4 ) ;
F_28 ( & V_7 -> V_18 -> V_24 ) ;
F_31 ( V_51 ) ;
V_60:
F_31 ( V_3 ) ;
V_59:
F_31 ( V_33 ) ;
V_58:
return V_39 ;
}
void F_39 ( struct V_6 * V_7 , int V_39 )
{
struct V_1 * V_2 = & V_7 -> V_18 -> V_27 ;
if ( V_39 < 0 )
return;
F_25 ( & V_7 -> V_18 -> V_24 ) ;
F_10 ( V_39 , & V_2 -> V_4 ) ;
if ( F_33 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_5 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_28 ( & V_7 -> V_18 -> V_24 ) ;
}
