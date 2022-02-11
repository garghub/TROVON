static struct V_1 * F_1 ( char * V_2 , T_1 V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_1 V_5 ;
T_1 V_6 ;
if ( V_3 < sizeof( struct V_1 ) )
goto V_7;
V_5 . V_8 = F_2 ( * ( V_9 * ) ( V_2 ) ) - 1 ;
V_5 . V_10 = F_2 ( * ( V_9 * ) ( V_2 + 2 ) ) ;
V_5 . V_11 = F_3 ( * ( V_12 * ) ( V_2 + 8 ) ) ;
V_2 += sizeof( struct V_1 ) ;
if ( ! ( V_5 . V_10 == V_13 || V_5 . V_10 == V_14 ||
V_5 . V_10 == V_15 ) )
goto V_7;
V_6 = F_4 ( V_5 . V_11 , V_5 . V_10 ) ;
if ( V_3 < V_6 )
goto V_7;
V_4 = F_5 ( V_6 ) ;
if ( V_4 ) {
* V_4 = V_5 ;
if ( V_5 . V_10 == V_15 )
F_6 ( V_4 -> V_16 , V_2 , V_5 . V_11 ,
V_17 , V_18 ) ;
else if ( V_5 . V_10 == V_13 )
F_6 ( V_4 -> V_16 , V_2 , V_5 . V_11 ,
V_9 , F_2 ) ;
else if ( V_5 . V_10 == V_14 )
F_6 ( V_4 -> V_16 , V_2 , V_5 . V_11 ,
V_12 , F_3 ) ;
else
goto V_19;
}
V_7:
if ( F_7 ( V_4 ) )
F_8 () ;
return V_4 ;
V_19:
F_9 ( V_4 ) ;
return NULL ;
}
static int F_10 ( struct V_20 * V_21 , int V_22 )
{
T_1 V_23 , V_24 , V_25 ;
int error = - V_26 ;
if ( ! ( V_21 -> V_27 [ V_28 ] &&
V_21 -> V_27 [ V_29 ] &&
V_21 -> V_27 [ V_30 ] && V_21 -> V_27 [ V_31 ] ) )
goto V_7;
V_24 = V_21 -> V_27 [ V_29 ] -> V_11 ;
if ( F_11 ( V_22 ) ) {
if ( ! V_21 -> V_27 [ V_32 ] )
goto V_7;
if ( V_24 != V_21 -> V_27 [ V_32 ] -> V_11 )
goto V_7;
}
if ( F_12 ( V_22 ) ) {
if ( ! V_21 -> V_27 [ V_33 ] )
goto V_7;
if ( V_24 != V_21 -> V_27 [ V_33 ] -> V_11 )
goto V_7;
}
if ( V_24 != V_21 -> V_27 [ V_28 ] -> V_11 )
goto V_7;
V_25 = V_21 -> V_27 [ V_30 ] -> V_11 ;
if ( V_25 != V_21 -> V_27 [ V_31 ] -> V_11 )
goto V_7;
if ( V_21 -> V_27 [ V_34 ] &&
V_21 -> V_27 [ V_34 ] -> V_11 != 256 )
goto V_7;
if ( V_22 & V_35 ) {
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( F_13 ( V_21 ) [ V_23 ] >= V_24 )
goto V_7;
if ( F_14 ( V_21 ) [ V_23 ] + 255 >= V_25 ) {
F_15 ( V_36 L_1
L_2 ) ;
goto V_7;
}
}
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
if ( F_16 ( V_21 ) [ V_23 ] >= V_24 )
goto V_7;
if ( F_17 ( V_21 ) [ V_23 ] >= V_24 )
goto V_7;
}
}
error = 0 ;
V_7:
return error ;
}
static void F_18 ( struct V_20 * V_21 )
{
if ( V_21 ) {
int V_23 ;
for ( V_23 = 0 ; V_23 < F_19 ( V_21 -> V_27 ) ; V_23 ++ ) {
F_9 ( V_21 -> V_27 [ V_23 ] ) ;
V_21 -> V_27 [ V_23 ] = NULL ;
}
F_20 ( V_21 ) ;
}
}
void F_21 ( struct V_37 * V_37 )
{
struct V_20 * V_21 = F_22 ( V_37 , struct V_20 , V_38 ) ;
F_18 ( V_21 ) ;
}
struct V_20 * F_23 ( void * V_2 , T_1 V_39 , int V_22 )
{
int V_40 ;
int error = - V_41 ;
char * V_42 = V_2 ;
struct V_1 * V_4 = NULL ;
struct V_20 * V_21 = F_24 ( sizeof( struct V_20 ) , V_43 ) ;
if ( ! V_21 )
goto V_19;
F_25 ( & V_21 -> V_38 ) ;
error = - V_26 ;
if ( V_39 < sizeof( struct V_44 ) )
goto V_19;
if ( F_26 ( * ( V_12 * ) V_42 ) != V_45 )
goto V_19;
V_40 = F_26 ( * ( V_12 * ) ( V_42 + 4 ) ) ;
if ( V_39 < V_40 )
goto V_19;
V_21 -> V_22 = F_27 ( * ( V_9 * ) ( V_42 + 12 ) ) ;
V_42 += V_40 ;
V_39 -= V_40 ;
while ( V_39 > 0 ) {
V_4 = F_1 ( V_42 , V_39 ) ;
if ( ! V_4 )
goto V_19;
switch ( V_4 -> V_8 ) {
case V_32 :
if ( ! ( V_4 -> V_10 & F_11 ( V_22 ) ) )
goto V_19;
break;
case V_33 :
if ( ! ( V_4 -> V_10 & F_12 ( V_22 ) ) )
goto V_19;
break;
case V_29 :
if ( V_4 -> V_10 != V_14 )
goto V_19;
break;
case V_28 :
case V_30 :
case V_31 :
if ( V_4 -> V_10 != V_13 )
goto V_19;
break;
case V_34 :
if ( V_4 -> V_10 != V_15 )
goto V_19;
break;
default:
goto V_19;
}
if ( V_21 -> V_27 [ V_4 -> V_8 ] )
goto V_19;
V_21 -> V_27 [ V_4 -> V_8 ] = V_4 ;
V_42 += F_4 ( V_4 -> V_11 , V_4 -> V_10 ) ;
V_39 -= F_4 ( V_4 -> V_11 , V_4 -> V_10 ) ;
V_4 = NULL ;
}
error = F_10 ( V_21 , V_22 ) ;
if ( error )
goto V_19;
return V_21 ;
V_19:
F_9 ( V_4 ) ;
F_18 ( V_21 ) ;
return F_28 ( error ) ;
}
unsigned int F_29 ( struct V_20 * V_21 , unsigned int V_46 ,
const char * V_47 , int V_48 )
{
V_9 * V_49 = F_13 ( V_21 ) ;
V_12 * V_50 = F_14 ( V_21 ) ;
V_9 * V_51 = F_16 ( V_21 ) ;
V_9 * V_52 = F_17 ( V_21 ) ;
unsigned int V_53 = V_46 , V_54 ;
if ( V_53 == 0 )
return 0 ;
if ( V_21 -> V_27 [ V_34 ] ) {
V_17 * V_55 = F_30 ( V_21 ) ;
for (; V_48 ; V_48 -- ) {
V_54 = V_50 [ V_53 ] + V_55 [ ( V_17 ) * V_47 ++ ] ;
if ( V_52 [ V_54 ] == V_53 )
V_53 = V_51 [ V_54 ] ;
else
V_53 = V_49 [ V_53 ] ;
}
} else {
for (; V_48 ; V_48 -- ) {
V_54 = V_50 [ V_53 ] + ( V_17 ) * V_47 ++ ;
if ( V_52 [ V_54 ] == V_53 )
V_53 = V_51 [ V_54 ] ;
else
V_53 = V_49 [ V_53 ] ;
}
}
return V_53 ;
}
unsigned int F_31 ( struct V_20 * V_21 , unsigned int V_46 ,
const char * V_47 )
{
return F_29 ( V_21 , V_46 , V_47 , strlen ( V_47 ) ) ;
}
